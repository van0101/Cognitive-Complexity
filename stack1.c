#include<stdio.h>
//#include "inputinteger.c"

typedef struct stack
{
   int info;
   struct    stack *next;
   struct stack *previous;
}
stack;
stack *s;
stack *top;
stack *drag;


createstack()
{
    s=NULL;//create emoty stack;
}
push(int element)
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

int pop()
{
    int x;
    stack *ptr;
    if(!stackisempty())
    {
    ptr=top;
    top=top->previous;
    x=ptr->info;
    free(ptr);
    printf("pop is %d\n",x);
    }
    else
    {
        printf("stack is empty ..cannot pop element\n");
        getch();
    }


    return x;
}
int peek()
{
    int x;
    x=top->info;
    return x;
}


