//Purpose:Singly Link List
#include<stdio.h>  // Pre-Processive to include standard input and output funtion header files.
#include<stdlib.h>   // Pre-Processive to include standard Libraray funtion header files.

struct node   

{  
    int data;  
    struct node *next;   
};
typedef struct node Node;  
Node *head=NULL;  
  
void Insert_1st ();   // Funtion Prototype 
void randominsert();  // Funtion Prototype
void random_delete();  // Funtion Prototype
void display();   // Funtion Prototype
void search();  
void main ()  
{  
    int choice;
    while(1)   
    {  
        printf("\nMain menu");     
        printf("\n1.Insert in begining");
        printf("\n2.Insert At Specified Position");
        printf("\n3.Delete From A Spefic Position");
        printf("\n4.View ");
        printf("\n5.Search ");
        printf("\n6.Exit From Program"); 
        printf("\nEnter your choice\n");         
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:  
              Insert_1st (); 
            break;  
            case 2:  
            randominsert();      
            break;  
            case 3:  
            random_delete();          
            break;  
            case 4:  
            display();        
            break;  
            case 5:  
            search();        
            break;  
            case 6:  
            exit(0);  
            break;  
            default:  
            printf("Please enter valid choice..");  
        }  
    }  
}  
void Insert_1st ()
{  
    Node *ptr;  
    int item;  
    ptr = (struct node *) malloc(sizeof(struct node *));  
    if(ptr == NULL)  
    {  
        printf("\nNo Memory available in ram");  
    }  
    else  
    {  
        printf("\nEnter value\n");    
        scanf("%d",&item);    
        ptr->data = item;      
        ptr->next = head;  
        head = ptr;  
        printf("\n Node Succesfully inserted\n");
        printf("\n%d is added In List",item)  ;
    }  
      
}  

void randominsert()  
{  
    int i,loc,item;   
    Node *ptr, *temp;  
    ptr = (struct node *) malloc (sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("\nNo memory available in ram");  
    }  
    else  
    {  
        printf("\nEnter element value");  
        scanf("%d",&item);  
        ptr->data = item;  
        printf("\nEnter the location after which you want to insert ");  
        scanf("\n%d",&loc);  
        temp=head;  
        for(i=0;i<loc;i++)  
        {  
            temp = temp->next;  
            if(temp == NULL)  
            {  
                printf("\ncan't insert\n");  
                return;  
            }  
          
        }  
        ptr ->next = temp ->next;   
        temp ->next = ptr;   
        printf("\nNode inserted");  
    }  
}  
void random_delete()  
{  
    Node *ptr,*ptr1;  
    int loc,i;    
    printf("\n Enter the location of the node after which you want to perform deletion \n");  
    scanf("%d",&loc);  
    ptr=head;  
    for(i=0;i<loc;i++)  
    {  
        ptr1 = ptr;       
        ptr = ptr->next;  
              
        if(ptr == NULL)  
        {  
            printf("\nCan't delete");  
            return;  
        }  
    }  
    ptr1 ->next = ptr ->next;  
    free(ptr);  
    printf("\nDeleted node %d ",loc+1);  
}  
void search()  
{  
    Node *ptr;  
    int item,i=0,flag;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("\nEmpty List\n");  
    }  
    else  
    {   
        printf("\nEnter item which you want to search?\n");   
        scanf("%d",&item);  
        while (ptr!=NULL)  
        {  
            if(ptr->data == item)  
            {  
                printf("\nitem found at location %d \n",i+1);  
                printf("\nitem found at Index %d \n ",i);  
                flag=0;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            ptr = ptr -> next;  
        }  
        if(flag==1)  
        {  
            printf("Item not found\n");  
        }  
    }     
          
}  
  
void display()  
{  
    Node *ptr;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("Nothing to print");  
    }  
    else  
    {  
        printf("\nprinting values . . . . .\n");   
        while (ptr!=NULL)  
        {  
            printf("\n%d",ptr->data);  
            ptr = ptr -> next;  
        }  
    }  
}     
