#include<arpa/inet.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<strings.h>
#include<signal.h>

void sendFile(FILE *f, struct sockaddr_in addr, int sockfd);
void signalHandler(int s);

int sockfd, newsockfd, n, clientAdressLen;

int main(int argc, char *argv[]){
    char buffer[256]; 
    struct sockaddr_in server_addr, client_addr; 
    FILE *f;
    char *file = "server.txt";

    if( argc < 3){ 
        fprintf(stderr,"%s hostname port fileName \n", argv[0]);
        exit(1);
    }

    signal(SIGINT,&signalHandler);

    server_addr.sin_family = AF_INET; 
    server_addr.sin_port = htons(atoi(argv[2])); 
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    
    if(sockfd < 0){
        perror("[ERROR] Socket opening error \n");
        exit(1);
    }  

    printf("[INFO] Socket running \n");
    
    n = bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    
    if(n < 0){
        perror("[ERROR] Bind error \n");
        exit(1);
    }

    printf("[INFO] Binded \n");

    listen(sockfd, 2);

    printf("[INFO] Server has been started \n");
    
    clientAdressLen = sizeof(client_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &client_addr, (socklen_t *) &client_addr);

    if(newsockfd < 0){ 
        perror("[ERROR] Error on accept \n");
        exit(1); 
    }

    printf("[INFO] Connection accepted \n");
    bzero(buffer, 256);
    n = read(newsockfd, buffer, 255);

    if(n < 0){
        perror("[ERROR] Error reading from socket \n");
        exit(1);
    }

    if(argc == 3){
        file = argv[3];
        f = fopen(file, "r");
    } else {
        f = stdin;
    }

    if(f == NULL){
        fprintf(stderr, "[ERROR] Error while opening the file \n");
        return 1;
    }

    sendFile(f, server_addr, sockfd);
    printf("[INFO] Transfer file complete \n");
    fclose(f);
    return 0;
}

void sendFile(FILE *f, struct sockaddr_in addr, int sockfd){ 
    int in;
    char buffer[256];
    while(fgets(buffer, 256, f) != NULL){
        printf("[INFO] Sending file \n");
        in = sendto(sockfd, buffer, 256, 0, (struct sockaddr *)&addr, sizeof(addr));
        if(in == -1){
            perror("[ERROR] Sending error \n"); 
            exit(1);
        }
        
        bzero(buffer, 256);
    }
    strcpy(buffer, "END");  
    sendto(sockfd, buffer, 256, 0, (struct sockaddr *)&addr, sizeof(addr));
    fclose(f);
}

void signalHandler(int s){
    close(sockfd);
    printf("[INFO] Socked closed sucess /n");
}