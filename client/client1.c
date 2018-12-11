#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#define PORT 5678
int main()
{
int sockid;
sockid=socket(AF_INET,SOCK_STREAM,0);
if(sockid==-1)
{
printf("Socket Error\n");
return 0;
}
int i;
struct sockaddr_in client;
client.sin_family=AF_INET;
client.sin_port=htons(PORT);
client.sin_addr.s_addr=INADDR_ANY;
for(i=0;i<8;i++)
{
client.sin_zero[i]='\0';
}
int connectstatus;
connectstatus=connect(sockid,(struct sockaddr*)&client,sizeof(struct sockaddr));
if(connectstatus==-1)
{
printf("Connection Error\n");
return 0;
}
printf("\n\nConnected to Server\n\n");
while(1)
{
char message[30];
printf("Enter your query: ");
scanf(" %s",message);
char remsg[30];
int sentbytes=send(sockid,message,strlen(message),0);
if(strcmp(message,"bye")==0)
break;
int recvbytes=recv(sockid,remsg,sizeof(remsg),0);
printf("Message from server ..\n");
printf("%s",remsg);
}
close(sockid);
return 0;
}

