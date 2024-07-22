



#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>


int main(){
const char * hello="hello from client";
struct sockaddr_in servaddr;
char buffer[1024]={0};
int sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd==-1){
perror("failed to create socket");
exit(EXIT_FAILURE);
}
servaddr.sin_family=AF_INET;
servaddr.sin_port=htons(8080);
servaddr.sin_addr.s_addr=INADDR_ANY;
if(connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr))<0){
	perror("error");
	exit(1);
	}
int len=sendto(sockfd,(const char *)hello,strlen(hello),0,(const struct sockaddr *)&servaddr, sizeof(servaddr));
if(len==-1){
	perror("failed to send");
	exit(1);
	}
if(read(sockfd,buffer,1024)<0){
	perror("error on reading");
	exit(1);
	}
printf("server: \n%s",buffer);
	close(sockfd);
	return 0;
	}
