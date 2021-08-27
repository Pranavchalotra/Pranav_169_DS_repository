//Purpose:Write a program to check if a given expression is correctly parenthesized using Stacks.
#include<stdio.h>
#include<stdlib.h>
int top = -1;
char stack[100];
// to push elements in stack
void push(char a)
{
      stack[top] = a;
      top++;
}
// to pop elements from stack
void pop()
{
      if (top == -1)
      {
            printf("expression is invalid\n");
            exit(0);
      }
      else
      {
            top--;
      }
}
int main()
{
  int i,cho=0;
  char a[100];
  printf("\tMENU");
  printf("\n\t1.Check expression correctly parenthesized\n2.Exit\n");
  while (cho!=2)
  {
    printf("Choose operation : ");
    scanf("%d", &cho);
    switch (cho)
    {
      case 1:
      printf("\nEnter expression : ");
      scanf("%s",a);
      for (i = 0; a[i] != '\0';i++)
        {
           if (a[i] == '('||a[i]=='{'||a[i]=='[')
               {
                  push(a[i]);
                }
                              
            else if (a[i] == ')'||a[i]=='}'||a[i]==']')
                {
                   pop();
                 }
        }
            if (top == -1)
              printf("Expression is valid\n\n");
            else
              printf("Expression is invalid\n\n");
              break;
            case 2:
                  exit(0);
                  default: printf("Invalid operation...");
            }
      }
      return 0;
}
