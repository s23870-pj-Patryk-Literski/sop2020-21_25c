#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
 
int executeActions(int connected_socket, char* filename, struct addrinfo *addr_p) 
{
  int arglen = strlen(filename);
      
  write(connected_socket, &arglen,sizeof(arglen));
  write(connected_socket, filename, arglen);
  int fileContentSize = 0;
  read(connected_socket, &fileContentSize, sizeof(int));
 
  if (fileContentSize == -1)
  {
    printf("File does not exist.");
    return -1;
  }
  char* fileContent = (char *)malloc(fileContentSize);
  read(connected_socket, fileContent, fileContentSize);
  fileContent[fileContentSize] = 0;
  writeToFile(fileContent, filename);

free(fileContent);
  close(connected_socket);
  freeaddrinfo(addr_p); 
  return 0;             
}

void writeToFile(char* fileContent, char* filename)
{
  FILE *file;
  file = fopen("filename2.txt", "w");
  fprintf(file, fileContent);
 
  fclose(file);
}
 
int main(int argc, char **argv) {
  struct addrinfo hints;
  bzero((char *)&hints, sizeof(struct addrinfo));

hints.ai_family = AF_UNSPEC;     
  hints.ai_socktype = SOCK_STREAM; 
 
  struct addrinfo *addr_p;
  int err = getaddrinfo(argv[1], argv[2], &hints, &addr_p);
 
  if (err) {
    fprintf(stderr, gai_strerror(err));
    return -1;
  }

struct addrinfo *rp;

for (rp = addr_p; rp != NULL; rp = rp->ai_next) {
    int connected_socket =
        socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
    
    if (connected_socket != -1) {
      if (connect(connected_socket, rp->ai_addr, rp->ai_addrlen) != -1) {
        return executeActions(connected_socket, argv[3], addr_p);
      }
    }
  }
  freeaddrinfo(addr_p);
  fprintf(stderr, "could not open connection\n");
  return -1;
}