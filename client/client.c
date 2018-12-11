#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#define PORT 5679
void files(char *wordd)
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
        char temp[100];
        strcpy(wordd,line);
    }
    pos = ftell(file);
}

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

char message[30];
i=0;
int flag=0;
system("python location.py");
printf("Choose \n 1.Query \n 2.Exit");
while(flag==0)
{
scanf("%d",&i);
 if(i==1)
  {
   printf("I am Sending 1");
   strcpy(message,"query");
   flag=-1;
  }
 else if(i==2)
  {
   strcpy(message,"byeee");
   flag=-1;
  }
  
  if(flag!=-1)
  {
  system("clear");
  printf(" \n ReEnter the better option \n ");
  }
}

int sentbytes=send(sockid,message,strlen(message),0);
if(strcmp(message,"byeee")==0)
{
printf("Message from server : Bye..\n");
close(sockid);
return 0;
}
 
char remsg[30],remsg1[30];
int recvbytes=recv(sockid,remsg,sizeof(remsg),0);
                

                
int recvbytes1=recv(sockid,remsg1,sizeof(remsg1),0);

printf("Connected in as %s",remsg1);

if(strcmp(remsg,"query")==0)
{



printf("Message from server .. Success \n");
system(" gnome-terminal --tab -e \"node app.js\" --tab --tab ");
		
system("google-chrome http://localhost:8080/test");


printf("Enter 1 to get the results");
scanf("%d",&i);


if(i==1)
{
system("bash code.sh temp");
    
    


FILE *fptr;
    char filename[15];
    char ch;
 
    //printf("Enter the filename to be opened \n");
    //scanf("%s", filename);
    /*  open the file for reading */
    fptr = fopen("exp_temp_tempstorages.txt", "r");
    if (fptr == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }
    ch = fgetc(fptr);
     char string[500];
       int t=0;
    while (ch != EOF)
    {
        printf ("%c", ch);
        string[t++]=ch;
        ch = fgetc(fptr);
         
    }

char sub[100];
int length=strlen(string);
int l=length-8;
int c=0;
int position=55;
while (c < l) {
      sub[c] = string[position+c-1];
      c++;
   }
   sub[c] = '\0';
 

char resultquer[100];
c=0;
int sublen=strlen(sub);

while(c<sublen)
{
if(sub[c]=='"')
{
break;
}
resultquer[c]=sub[c];
c++;
}
resultquer[c]='\0';
fclose(fptr);


printf("%s",resultquer);

char resultquery[100];
strcpy(resultquery,"find /home -name ");
strcat(resultquery,resultquer);
strcat(resultquery,">>open.txt");
//char wordd[100];
//files(wordd);


//strcat(resultquery,remsg1);

printf("%s",resultquery);



printf("Enter 1 to get the results");
scanf("%d",&i);


system(resultquery);


system("python calculate.py");

printf("MANIPULATING THE RESULTS PRESS1 IF YOU WISH TO SEE THE UPDATEDLIST");
int vl;
scanf("%d",&vl); //wait for python to execute

system("awk -F, '{ print $2, $1 }' resultfrequency.txt | sort -rnk2>>resultprocessing.txt");


char querrr[1000];
strcpy(querrr,"grep ");
strcat(querrr,resultquer);
strcat(querrr," resultprocessing.txt>>out.txt");

//to find the result alone

system(querrr);



system("rm op.txt");

system("python pagerank.py");



system("google-chrome file:///home/mrchaos10/Desktop/NetworksProj/client/op.txt");


}

}
close(sockid);
return 0;
}

