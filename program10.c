#include <stdio.h>  
#include <stdlib.h>
void push();  
void pop();  
void display();  
int count=0;
struct node  
{  
        int data;  
        struct node *next;  
};
typedef struct node Node;  
Node *head=NULL; 
int main()
{
    int choice;
    while(1){
                printf("\n~Stack Operation using Singly Linked List~");
                printf("\n 1. Push a node.");
                printf("\n 2. Pop a node.");
                printf("\n 3. Display all nodes.");
                printf("\n 4. Exit the proggram.");
                printf("\n Enter your choice: ");
                scanf("%d",&choice);
                switch(choice)
                {
                    case 1:
                            printf("\n~Implementing insert function!~\n");
                            printf("\nNumber of nodes available: %d", count);
                            push();
                            break;
                    case 2:
                            printf("\n~Implementing delete function!~\n");
                            printf("\nNumber of nodes available: %d", count);
                            pop();
                            break;
                    case 3:
                            printf("\n~Implementing display function!~\n");
                            printf("\nNumber of nodes available: %d", count);
                            display();
                            break;    
                    case 4:
                            printf("Exiting the program!");
                            exit(0);
                            break;
                    default:
                            printf("\nWrong Choice! :/");
                            break;
                }
        }
        return 0;
}
 
void push ()  
{  
    int val;  
    Node *ptr = (struct node*)malloc(sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("\nNo memory in the ram ");  
    }  
    else  
    {  
        printf("\nEnter the value: ");  
        scanf("%d",&val);  
        if(head==NULL)  
        {        
            ptr->data = val;  
            ptr -> next = NULL;  
            head=ptr;  
        }  
        else  
        {  
            ptr->data = val;  
            ptr->next = head;  
            head=ptr;  
               
        }
        count++;
    }  
}  
 
void pop()  
{  
    int item;  
    Node *ptr;  
    if (head == NULL)  
    {  
        printf("\nNo memory in the ram");  
    }  
    else  
    {  
        item = head->data;  
        ptr = head;  
        head = head->next;  
        free(ptr);
        count--;
    }  
}

void display()  
{  
    int i;  
    Node *ptr;  
    ptr=head;  
    if(ptr == NULL)  
    {  
        printf("\nStack is empty! :/");  
    }  
    else  
    {  
        printf("\nNodes in stack are:");  
        while(ptr!=NULL)  
        {  
            printf(" %d,",ptr->data);  
            ptr = ptr->next;  
        }  
    }  
}

