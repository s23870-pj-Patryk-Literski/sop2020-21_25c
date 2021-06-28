#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <arpa/inet.h>
#define SIZE 1024
#define h_addr h_addr_list[0]

int main(int argc, char *argv[]){
	int cli_socket, portno, n;
	
	struct sockaddr_in serv_addr;
    struct hostent *server;
    
	char buffer[256];
    if (argc != 3) {printf("argument_error\n");exit(1);}
	portno = atoi(argv[2]);
	
	cli_socket = socket(AF_INET, SOCK_STREAM, 0);
	if(cli_socket < 0){printf("opening_socket_error\n");exit(1);}
	
	server = gethostbyname(argv[1]);
	if(server == NULL){printf("host_error\n");exit(1);}
	
	bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(cli_socket,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) 
        {printf("connecting_error\n");exit(1);}
	
    printf("Please enter the message: ");
    bzero(buffer,256);
    fgets(buffer,255,stdin);
    n = write(cli_socket,buffer,strlen(buffer));
    if (n < 0){printf("writing_error\n");exit(1);}
    bzero(buffer,256);
    n = read(cli_socket,buffer,255);
    if (n < 0){printf("readig_error\n");exit(1);}
    printf("%s\n",buffer);
	
	write_file(serv_addr);
	printf("[+]Data written in the file successfully.\n");
	
	close(cli_socket);
    return 0;
}

void write_file(int serv_addr){
  int n;
  FILE *transfer;
  char *filename = "pliczek";
  char buffer[SIZE];

  transfer = fopen(filename, "w");
  while (1) {
    n = recv(serv_addr, buffer, SIZE, 0);
    if (n <= 0){
      break;
      return;
    }
    fprintf(transfer, "%s", buffer);
    bzero(buffer, SIZE);
  }
  return;
}
