#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<strings.h>

void sendFile(FILE *fp, int sockfd, struct sockaddr_in addr){
    int n;
    char buffer[256];

    while(fgets(buffer, 256, fp) != NULL){
        printf("[SENDING] Sending file: %s", buffer);
        n = sendto(sockfd, buffer, 256, 0, (struct sockaddr *)&addr, sizeof(addr));
        if(n == -1){
            perror("[ERROR] Sending error!!!");
            exit(1);
    }
        bzero(buffer, 256);
    }

    strcpy(buffer, "END");
    sendto(sockfd, buffer, 256, 0, (struct sockaddr *)&addr, sizeof(addr));
    fclose(fp);
}
int main(int argc, char *argv[]){
    int sockfd, newsockfd, portNO, n;    
    char buffer[256];
    socklen_t clientAdressLen;
    struct sockaddr_in server_addr, client_addr;
    FILE *fp;
    char *fileName = "paczka1.txt";

    if( argc < 2){
        fprintf(stderr, "[ERROR] No port provided\n");
        exit(1);
    }
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if(sockfd < 0){
        perror("[ERROR] Socket opening error!!");
        exit(1);
    }  
    printf("[SUCCESS] Socket runned\n");
    portNO = atoi(argv[1]);
    server_addr.sin_family = AF_INET; 
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    n = bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    if(n < 0){
        perror("[ERROR] Bind error!!!");
        exit(1);
    }
    printf("[SUCCESS] Bind OK\n");
    listen(sockfd, 5);
    printf("[STARTING] Server has been started\n");
    clientAdressLen = sizeof(client_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, (socklen_t *)&clientAdressLen);
    if(newsockfd < 1){
        perror("[ERROR] Error on accept!!!\n");
        exit(1);
    }
    printf("Connection accepted :)");
    bzero(buffer, 256);
    n = read(newsockfd, buffer, 255);

    if(n < 0){
        perror("[ERROR] Error reading from socket");
        exit(1);
    }
    printf("Here is the message: %s\n", buffer);
    n = write(newsockfd, "I got your message", 18);

    if(n < 0){
        perror("[ERROR] Error writing to socket");
    }

    if(argc == 2){
        fileName = argv[1];
        fp = fopen(fileName, "r");
    }else {
        fp = stdin;
    }

    if(fp == NULL){
        fprintf(stderr, "[ERROR] Error while opening the file\n");
        return 1;
    }

    sendFile(fp, sockfd, server_addr);
    printf("[SUCCESS] Transfer file complete\n");
    printf("[CLOSING] Closing the connection\n");
    fclose(sockfd);
    return 0;
}