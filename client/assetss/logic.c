#include<stdio.h>
void files()
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
    }
    pos = ftell(file);

}
int main()
{
files();
files();
files();         

return 0;
}
