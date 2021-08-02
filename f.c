#include <stdio.h>
#include <stdlib.h>
#include "stack1.h"

void chk(char s[100]);
int if_count=0,for_count=0,else_count=0,while_count=0,do_count=0,elseif_count=0;
void read_file();
int main()
{
    createstack();
    push('!');
    read_file();
}
void read_file()
{
    FILE *fptr;

    char filename[100], c;
    char s[100];

    int i=0;
    printf("Enter the filename to open \n");
    scanf("%s", filename);

    // Open file
    fptr = fopen(filename, "r");//Open file to read only
    if (fptr == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }

    // Read contents from file
    c = fgetc(fptr);
    while (c != EOF)
    {
        s[i]=c;
        i++;

        chk(s);//check for the keyword

        if(c=='\n')
        {
            i=0;
            int n;
            for(n=0;n<100;n++)
                s[n]='\0';

        }
        c = fgetc(fptr);
    }

    fclose(fptr);

    printf("if:%d \nfor:%d \nelse:%d \nwhile: %d\ndo-while: %d\nelse if: %d\n",if_count,for_count,else_count-elseif_count,(while_count-do_count),do_count,elseif_count);
    printf("Total Cognitive Complexity is %d\n",if_count+for_count+else_count+while_count);//while_cont=while_count-do_count else_count=else_count-elseif_count

}
void chk(char s[100])
{
    char keys[8][100]={"if","else","for","{","}","while","do","elseif"};
    //                                   0     1         2      3   4       5           6       7

    int i;
    for(i=0;i<8;i++)
    {
        if(strcmp(s,keys[i])==0)//if same then 0 else 1
           {
               if(i==0)
               {
                   if_count++;
                   if(peek()=='{')//the statement is nested
                        if_count++;
                    break;
               }
               if(i==1)
               {
                   else_count++;
                   if(peek()=='{')
                    else_count++;
                    break;
               }
               if(i==2)
               {
                   for_count++;
                   if(peek()=='{')
                    {
                        for_count++;
                    }
                   break;
               }
               if(i==3)
               {
                   push(keys[i][0]);
                   break;
               }
               if(i==4)
               {
                   pop();
                   break;
               }
               if(i==5)
               {
                   while_count++;
                   if(peek()=='{')
                    while_count++;
                    break;
               }
               if(i==6)
               {
                   do_count++;
                   if(peek()=='{')
                    do_count++;
                    break;
               }
               if(i==7)
               {
                   elseif_count++;
                   if(peek()=='{')
                    elseif_count++;
                    break;
               }
           }
    }
}
