#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<stdlib.h>
#include<unistd.h>
#include<strings.h>
#include<string.h>
#include<signal.h>
#include<stddef.h>

void writeFile(int sockfd, struct sockaddr_in addr){
    FILE *fp;
    char *fileName;
    int n;
    char buffer[256];
    socklen_t addr_size;
    fp = fopen(fileName, "w");
    while(1){
        addr_size = sizeof(addr);
        n = recvfrom(sockfd, buffer, 256, 0, (struct sockaddr *)&addr, &addr_size);
        if(strcmp(buffer, "END") == 0){
            break;
            return;
        }
        printf("[RECEIVING]FILE: %s", buffer);
        bzero(buffer, 256);
    }
    fclose(fp);
    return;
}
typedef void(*handler)(int);


// void registerHandler(int signal, handler handle, sigset_t signalBloackingMask){
//     struct sigaction setup_action;
//     setup_action.sa_handler = handle;
//     setup_action.sa_mask = signalBlockingMask;
//     setup_action.sa_flags = 0;
//     sigaction(signal, &setup_action, NULL);
// }
int main(int argc, char *argv[]){
    char buffer[256];
    int sockfd, newsockfd, clientAdressLen, n;
    struct sockaddr_in server_addr;

    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd < 0){
        perror("[ERROR] Socket error!!");
        exit(1);
    }  
   
    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if(connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0){
        perror("[ERROR] Connecting error!!!");
        
    }
    printf("Please enter the message: ");
    bzero(buffer,256);
    fgets(buffer,255,stdin);
    n = write(sockfd,buffer,strlen(buffer));
    if (n < 0){
         perror("ERROR writing to socket");
    }
    bzero(buffer,256);
    n = read(sockfd,buffer,255);
    if (n < 0){
         perror("ERROR reading from socket");
    }
    printf("%s\n",buffer);
    writeFile(sockfd, server_addr);
    return 0;
}
