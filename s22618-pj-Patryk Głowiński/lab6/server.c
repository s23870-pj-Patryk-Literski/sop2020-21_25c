#include <netdb.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <signal.h>
 
int listening_socket = 0;
 
int connected_socket_ready(int connected_socket, struct sockaddr_in *client) {
  FILE *logFile;
  char *fileName;
  int filenameSize;
  logFile = fopen("server.log", "a");
 
  read(connected_socket, &filenameSize, sizeof(int));
  fileName = (char *)malloc(filenameSize + 1);
  read(connected_socket, fileName, filenameSize);
  fileName[filenameSize] = 0;
  
  printf("received \"%s\"\n", fileName);
  char *clientIpAddress = inet_ntoa(client->sin_addr);
  int *clientPort = ntohs(client->sin_port);
  fprintf(logFile, "Client %s:%d requested for %s\n", clientIpAddress, clientPort, fileName);

  FILE *infile;
  char *buffer;
  long numbytes;

  infile = fopen(fileName, "r");


if(infile == NULL)
  {
    int error = -1;
    printf("%d", error);
    write(connected_socket, &error, sizeof(error));
    return error;
  }

fseek(infile, 0L, SEEK_END);
  numbytes = ftell(infile);

fseek(infile, 0L, SEEK_SET);

buffer = (char*)calloc(numbytes, sizeof(char));

fread(buffer, sizeof(char), numbytes, infile);
  fclose(infile);

int bufferLen = strlen(buffer);
  write(connected_socket, &bufferLen, sizeof(bufferLen));
  write(connected_socket, buffer, numbytes);
 
  free(buffer);
  free(fileName);
  close(connected_socket); 
  fclose(logFile);
  return 0;
}
 
int listening_socket_ready(int listening_socket) {
  struct sockaddr_storage peer_addr;
  socklen_t peer_addr_len = sizeof(struct sockaddr_storage);
  int connected_socket =
      accept(listening_socket, (struct sockaddr *)&peer_addr, &peer_addr_len);
 
 
  if (connected_socket == -1) {
    fprintf(stderr, "could not accept connection!\n");
    return connected_socket;
  }
 
  char host_[NI_MAXHOST], service_[NI_MAXSERV];
  getnameinfo((struct sockaddr *)&peer_addr, peer_addr_len, host_, NI_MAXHOST,
              service_, NI_MAXSERV, NI_NUMERICSERV | NI_NUMERICHOST);
  printf("Accepted connection from: %s:%s\n", host_, service_);
  connected_socket_ready(connected_socket, &peer_addr);
 
  close(listening_socket); // stop listening on socket
  return 0;
}
 
void signalInterruptHandler(int signal)
{
  printf("Interrupt signal registered. Interrupting");
  close(listening_socket);
}
 
int main(int argc, char **argv) {
  const int max_queue = 32;
  signal(SIGINT, signalInterruptHandler);
  struct addrinfo hints;
  bzero((char *)&hints, sizeof(struct addrinfo));
 
  hints.ai_family = AF_UNSPEC;    
  hints.ai_socktype = SOCK_STREAM; 
  hints.ai_flags = AI_PASSIVE;    
 
  struct addrinfo *result, *rp;
  int s = getaddrinfo((argc >= 2) ? argv[1] : NULL, (argc >= 3) ? argv[2] : "9090",
                      &hints, &result);
  if (s != 0) {
    fprintf(stderr, gai_strerror(s));
    return -1;
  }

for (rp = result; rp != NULL; rp = rp->ai_next) {
    listening_socket = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
    if (listening_socket != -1) {
      int yes = 1;
      if (setsockopt(listening_socket, SOL_SOCKET, SO_REUSEADDR, &yes,
                     sizeof(yes)) == -1) {
        fprintf(stderr, "setsockopt( ... ) error\n");
        return -1;
      }
      if (bind(listening_socket, rp->ai_addr, rp->ai_addrlen) == 0) {
        freeaddrinfo(result);
        if (listen(listening_socket, max_queue) == -1) {
          fprintf(stderr, "listen error\n");
          return -1;
        }
        return listening_socket_ready(listening_socket);
      }
      close(listening_socket); // didn't work, let's close socket
    }
  }
  freeaddrinfo(result);
  fprintf(stderr, "error binding adress\n");
  return -1;
}