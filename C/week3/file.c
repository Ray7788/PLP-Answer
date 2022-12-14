#include <stdio.h>
#include<errno.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#define LINE_SIZE 256

void Subtit(const char*s1,const char *s2,const char *pathname)
{

    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);
    FILE *fileline=fopen(pathname,"r+");

    if(fileline==NULL)
    {
        perror("Fopen error!");
        exit(0);
    }
    struct stat filestate;
    stat(pathname,&filestate);
    char *filebuffer=(char *)malloc(sizeof(char)*(filestate.st_size+1));
    for (int i = 0,ch=0;ch!=EOF;i++)
    {
        ch = fgetc(fileline);
        filebuffer[i]=ch;
    }  
    fseek(fileline,0,SEEK_SET);    
    for (char *index_1 = filebuffer,*index_2 = filebuffer;;)
    {
        index_2 = strstr(index_1,s1);
        if(index_2)
        {
            for(int i=0;i<index_2-index_1;i++)
            {
                fputc(index_1[i],fileline);
            }
            for(int i=0;i<len_s2;i++)
            {
                fputc(s2[i],fileline);
            }
            index_1=index_2+len_s1;
        }
        else
        {
            while(*index_1!=EOF)
            {
                fputc(*index_1++,fileline);
            }
            break;
        }
    }
    free(filebuffer);
    fclose(fileline);
}

int main(int argc, char **argv) {
    FILE *fptr1, *fptr2;
    int ch;

    // open the file in directory: f
    fptr1 = fopen(argv[1], "r");
    // create a new file with f-processed
    fptr2 = fopen(strcat(argv[1],"-processed"), "w+");
    
    Subtit(argv[2], "", argv[1]);

    ch = fgetc(fptr1);
    fputc(ch,fptr2);

}
