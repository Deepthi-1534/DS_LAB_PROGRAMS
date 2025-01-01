#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int stack[SIZE], top=-1;

void push( int value)
{
    if(top==SIZE-1)
    printf("Stack is full..overflow");
    else
    {
        top++;
        stack[top]=value;
        printf("Value inserted into stack \n");
    }
}

void pop()
{
    if(top==-1)
    printf("Stack is empty...Underflow");
    else
    {
        printf("Deleted element : %d" , stack[top]);
        top--;
    }
}

void display()
{
    if(top==-1)
    printf("Stack is empty");
    else

    {
        int i;
        printf("Stack elements are : \n");
        for(i=top;i>=0;i--)
        {
            printf("%d \n" , stack[i]);
        }
    }
}

void main()
{
    int value , choice;
    while(1)
    {
        printf("1.Push Operation \n 2.Pop Operation \n 3. Display the stack \n 4.Exit ");
        printf("Enter your choice : \n");
        scanf("%d" , &choice);
        switch(choice)
        {
            case 1 :
            printf("Enter the value to be inserted : \n");
            scanf("%d",&value);
            push(value);
            break;

            case 2 :
            pop();
            break;

            case 3:
            display();
            break;

            case 4 :
            exit(0);

            default : 
            printf("Inavlid choice entered ");


        }

    }
}
