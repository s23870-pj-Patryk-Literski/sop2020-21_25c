#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<stdlib.h>
#include<unistd.h>
#include<strings.h>
#include<string.h>

void writeFile(int sockfd, struct sockaddr_in addr);

int main(int argc, char *argv[]){
    char buffer[256];
    int sockfd, newsockfd, clientAdressLen, n;
    struct sockaddr_in server_addr;

    if (argc < 3) {
       fprintf(stderr,"%s hostname port \n", argv[0]);
       exit(1);
    }

    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if(sockfd < 0){
        perror("[ERROR] Socket not opened success \n");
        exit(1);
    }  
   
    if(connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0){
        perror("[ERROR] Connectinon error \n");
        
    }

    bzero(buffer,256);
    n = read(sockfd,buffer,255);
    if (n < 0){
         perror("[ERROR] ERROR reading from socket \n");
    }

    printf("%s\n",buffer);
    writeFile(sockfd, server_addr);
    return 0;
}

void writeFile(int sockfd, struct sockaddr_in addr){
    FILE *f;
    char *file;
    int in;
    char buffer[256];
    socklen_t addr_size;
    f = fopen(file, "w");

    while(1){
        addr_size = sizeof(addr);
        in = recvfrom(sockfd, buffer, 256, 0, (struct sockaddr *)&addr, &addr_size);
        if(strcmp(buffer, "END") == 0){
            break;
            return;
        }
        printf("[INFO] FILE: %s \n", buffer);
        bzero(buffer, 256);
    }

    fclose(f);
    return;
}