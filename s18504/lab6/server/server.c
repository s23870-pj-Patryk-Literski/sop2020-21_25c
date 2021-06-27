#define _POSIX_SOURCE
#include<stdio.h>
#include<sys/types.h> 
#include<sys/socket.h>
#include<netinet/in.h>
#include<signal.h>
#include<string.h>
#include<unistd.h>
#include<bits/sigaction.h>
#define HOSTNAME "192.168.0.87" /** adres maszyny mojego laba w domowym LANie **/
#define SIZE 1024
#include <arpa/inet.h>

void registerHandler(void);
void signalHandler(int);	

int main(int argc, char *argv[])
{
	registerHandler();
	
	if(argc != 2){printf("arg_error\n");exit(1);}
	if(atoi(argv[1]) < 1 || atoi(argv[1]) > 65535){system("echo log: port error > log.txt");printf("port_error\n");exit(1);}
	system("echo log: port correct > log.txt");
	
	int serv_socket, entry_socket, portno, clilength, n;
	char buffer[256];
	
	struct sockaddr_in serv_addr, client_addr;
	serv_socket = socket(AF_INET, SOCK_STREAM, 0);
	if(serv_socket < 0){system("echo log: socket error >> log.txt");printf("opening_socket_error\n");exit(1);}
	system("echo log: socket created >> log.txt");
	
	bzero((char *) &serv_addr, sizeof(serv_addr));
	
	portno = atoi(argv[1]);
	
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(portno);
	serv_addr.sin_addr.s_addr = inet_addr(HOSTNAME);
	
	if (bind(serv_socket, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0){system("echo log: binding error >> log.txt");printf("bind_error\n");exit(1);}
	system("echo log: binding correct >> log.txt");
		
	listen(serv_socket,5);
	system("echo log: listening on socket >> log.txt");
	
	clilength = sizeof(client_addr);
	
	
	
	entry_socket = accept(serv_socket, (struct sockaddr *) &client_addr, &clilength);
	if (entry_socket < 0){system("echo log: connection error >> log.txt");printf("accept_error\n");exit(1);}
	system("echo log: connection accepted >> log.txt");
	
	struct sockaddr_in* pV4Addr = (struct sockaddr_in*)&client_addr;
	struct in_addr ipAddr = pV4Addr->sin_addr;
	
	char str[INET_ADDRSTRLEN];
	inet_ntop( AF_INET, &ipAddr, str, INET_ADDRSTRLEN );
	
	blackListCheck(str);
	
	bzero(buffer, 256);
	n = read(entry_socket,buffer,255);
	if (n < 0){system("echo log: reading error >> log.txt");printf("readig_error\n");exit(1);}
	system("echo log: reading correct >> log.txt");
	printf("Here is the message: %s\n",buffer);
    n = write(entry_socket,"I got your message",18);
	if (n < 0){system("echo log: writing error >> log.txt");printf("writing_error\n");exit(1);}
	system("echo log: writing correct >> log.txt");
	
	FILE *transfer;
    transfer = fopen("pliczek", "r");
    if(transfer == NULL){fprintf(stderr, "transfer_file_error\n");exit(1);}
	
	send_file(transfer, serv_socket);
	printf("[+]File data sent successfully.\n");
	printf("[+]Closing the connection.\n");
	
	system("echo log: closing connection >> log.txt");
	close(serv_socket); 
	return 0;
}

void signalHandler(int signum) {
    registerHandler();
    printf("\neleganckie wyjscie\n");
	exit(0);
}

void registerHandler(void) {
	struct sigaction setup_action;
	sigset_t new_mask;
	sigemptyset(&new_mask);
	setup_action.sa_handler = &signalHandler;
	setup_action.sa_mask = new_mask;
	setup_action.sa_flags = 0;
	sigaction(SIGINT, &setup_action, NULL);
}

void blackListCheck(char str[])
{
	system("echo log: blacklist ip checking >> log.txt");
	printf("sprawdzam ip klienta: %s\n",str);
	FILE *blist;
	blist = fopen("blacklist","r");
	if(blist == NULL){printf("black_list_file_error\n");exit(1);}
	char lines[INET_ADDRSTRLEN];
	/** musimy mieć plik blacklist z adresami zakazanymi w tym samym katalogu w którym jest serwer **/
	while ((fscanf(blist,"%[^\n]\n", lines))!= EOF)
	{	
		printf("porownuje ip: %s do %s\n",str, lines);
		if(str == lines){system("log: ip on blacklist, error >> log.txt");printf("ten adres jest na czarnej liscie\n");exit(0);}
	}	
	system("echo log: ip correct >> log.txt");
	fclose(blist);
}

void send_file(FILE *transfer, int serv_socket){
	int n;
	char data[SIZE] = {0};
	system("echo log: file sending >> log.txt");
	while(fgets(data, SIZE, transfer) != NULL) {
		if (send(serv_socket, data, sizeof(data), 0) == -1) {
      {printf("file_sending_error\n");exit(1);}
		}
    bzero(data, SIZE);
	system("echo log: file sended >> log.txt");
  }
}
