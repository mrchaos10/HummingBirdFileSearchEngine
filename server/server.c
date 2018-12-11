#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<time.h>
#include<sys/stat.h>
#include<netinet/in.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#define PORT 5679
void files(char * wordd)
{
     static long pos = 0;
    FILE* file = fopen("login.txt", "r");
    char line[256];
  
    if (file==NULL) 
    {
        perror ("Error reading file");
    }
    else
    {
        fseek(file , pos , SEEK_CUR);
        fgets(line, sizeof(line), file);
        printf("%s", line);
        strcpy(wordd,line);
        //printf("%s",wordd); 
    }
    pos = ftell(file);

}
int main()
{
        int sockid;
        sockid=socket(AF_INET,SOCK_STREAM,0);
        if(sockid==-1)
        {
                printf("Socket Error");
                return 0;
        }
        struct sockaddr_in server,dummy;
        server.sin_family=AF_INET;
        server.sin_port=htons(PORT);
        server.sin_addr.s_addr=INADDR_ANY;
        int bindstatus=bind(sockid,(struct sockaddr*)&server,sizeof(struct sockaddr));
        if(bindstatus==-1)
        {
                printf("Bind Error");
                return 0;
        }
        int listenstatus=listen(sockid,10);
        if(listenstatus==-1)
        {
                printf("Listen Error");
                return 0;
        }
        int size=sizeof(struct sockaddr);
	while(1)
	{
	int newsd=accept(sockid,(struct sockaddr*)&dummy,&size);
	printf("\nConnected in as :");
         char wordd[100];
        files(wordd);
	int pid=fork();
	if(pid==0)
	{

		char recvmsg[100],sendmsg[100];
		
		int recvbytes=recv(newsd,recvmsg,100,0);
		if(strcmp(recvmsg,"query")==0)
		{
			strcpy(sendmsg,"query");
                        printf("I have recieved 1");
		}
                else if(strcmp(recvmsg,"byeee")==0)
		{
			strcpy(sendmsg,"byeee");
		}
                
                printf("Message from client : %s\n",recvmsg);
		
                printf("Sending message %s",sendmsg);
                printf("Login Details");
                system("python location.py");
                send(newsd,sendmsg,sizeof(sendmsg),0);	
                   //printf("%s",wordd);        
                int c;
                printf("Enter 1 to transfer connection token");
                scanf("%d",&c);
                 printf("Connection Token is %s",wordd);

                send(newsd,wordd,sizeof(wordd),0);	

                }
	}
	close(sockid);
        return 0;        
}

