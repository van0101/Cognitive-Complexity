#include<stdio.h>
//#include "inputinteger.c"

typedef struct stack
{
   char info;
   struct stack *next;
   struct stack *previous;
}
stack;
stack *s;
stack *top;
stack *drag;


createstack()
{
    s=NULL;
    top=NULL;//create empty stack;
}
push(char element)
{

        if(s==NULL)
        {
            stack *ptr;

            ptr=malloc(sizeof(stack));
            ptr->info=element;
            ptr->next=NULL;
            ptr->previous=NULL;
            top=ptr;
            s=ptr;

        }
        else
        {
            stack *ptr;
            ptr=malloc(sizeof(stack));

            top->next=ptr;

            ptr->info=element;
            ptr->next=NULL;
            ptr->previous=top;

            top=ptr;
        }

    }


int stackisempty()
{
   if(s==NULL)
    return 1;
   else
    return 0;
}

void pop()
{
    char x;
    stack *ptr;
    if(!stackisempty())
    {
    ptr=top;
    top=top->previous;
    x=ptr->info;
    free(ptr);
    //printf("pop is %c\n",x);
    }
    else
    {
       // printf("stack is empty ..cannot pop element\n");
        getch();
    }


    //return x;
}
char peek()
{
    if(s==NULL)
        return '!';
    char x;
    x=top->info;
    return x;
}


