#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>                

void str_cli(FILE *fp, int sockfd,struct sockaddr* serv_address, int servlen)
{
   int bufsize = 1024, cont,n;
   char *buffer = malloc(bufsize);
    struct sockaddr_in cli;
      memset(&cli,0,sizeof(cli));
      cont=sizeof(cli);
if(fgets(buffer,bufsize,fp)!=NULL)
{
	sendto(sockfd,buffer,bufsize,0,serv_address,servlen); 

	//printf("inside the function");
  if(n=recvfrom(sockfd, buffer, bufsize, 0,(struct sockaddr *)&cli,&cont)>0)
    fputs(buffer,stdout);
  
}
printf("\nEnd\n");
}
int main(int argc,char *argv[])
{
  int create_socket;
  
  struct sockaddr_in address;
  if ((create_socket = socket(AF_INET,SOCK_DGRAM,0)) > 0)
  printf("The Socket was created\n");
  address.sin_family = AF_INET;
  address.sin_port = htons(15001);
  inet_pton(AF_INET,argv[1],&address.sin_addr);
//   if (connect(create_socket,(struct sockaddr *) &address, sizeof(address)) == 0)
//   	printf("The connection was accepted with the server %s...\n",argv[1]);
//   else
// 	printf("error in connect \n");
    
  str_cli(stdin,create_socket, (struct sockaddr *)&address,sizeof(address));
  return close(create_socket);
}
