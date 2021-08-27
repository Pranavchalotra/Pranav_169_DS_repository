Name: Pranav Chalotra
Roll No: 169
Cse A2

#include <stdio.h>

int i, n, stack[10], top=-1;

void push();
void pop();
void view();

int main ()
{
     int c;
     
    printf("Please enter the number of elements to be stored:\n");
    scanf("%d", &n);

    do
    {
       
        printf("\nPlease select a choise from the given\n");
        
        printf("\nPress 1 to Push \nPress 2 to Pop \nPress 3 to view \nPress 4 to Exit\n");
        scanf("%d", &c);

        switch (c)
        {
            case 1: 
            {
                push();
                break;
            }

            case 2:
            {
                pop();
                break;
            }

            case 3:
            {
                view();
                break;
            }

            case 4:
            {
                printf("\nYou have Exited the code\nHave a nice day\n");
                break;
            }

            default:
            {
                printf("\nThe entered choise is not available\n");
                break;
            }


        }

    }while (c != 4);
    
}

void push() 
{
    int val;
    if (top == n)
    printf("Stack is Overflow\n");

    else
    {
        printf("\nEnter the number you want to enter\n");
        scanf("%d", &val);
        top = top + 1;
        stack[top] = val;
    }
}

void pop ()
{
    if (top == -1)
        printf("Stack is Underflow\n");
    else
    {
        printf("\nThe element present at the end %d has been removed from the Stack\n", stack[top]);
        top = top - 1;
    }
}

void view ()
{
    printf("\nThe element present in the stack are:\n");
    for(i=top; i>=0; i--)
    {
        printf("%d\n", stack[i]);
    }
}
