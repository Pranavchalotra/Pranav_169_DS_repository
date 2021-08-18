//To sort out the prices from lower to higher of a certain item  

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data 
{
    char name[100];
    char item[100];
    int price;
    struct data *next;
};

void insert();
void delete();
void view();
void sort();
void search();

typedef struct data list;

list *head=NULL;

int main()
{
    int choise;
    while (choise != 6)
    {
        printf("\n\n------------------------------");
        printf("\nPress 1 to Enter a shop in the list\nPress 2 to remove a shop from the list \nPress 3 to Display the list\nPress 4 to sort the list\nPress 5 to Search a shop in the list\nPress 6 to Exit the list");
        printf("\n\nEnter your choise = ");
        scanf("%d", &choise);

        switch(choise)
        {
            case 1:
            insert();
            break;

            case 2:
            delete();
            break;

            case 3:
            view();
            break;

            case 4:
            sort();
            break;

            case 5:
            search();
            break;

            case 6:
            printf("\n\nYou have successfully Exited the code\nHave a Nice day");
            break;

            default:
            printf("\n\nYou have entered a wrong choise\nPlease try again");
            break;
        }
    }
}

void insert()
{
    list *ptr, *temp;

    ptr=(list *)malloc(sizeof(list));

    if(ptr == NULL)
    {
        printf("\n\nThere is no Space present to store more data\nPlease free some space and try again");
    }
    
    else
    {
        fflush(stdin);
        printf("\nEnter the name of the shop = ");
        gets(ptr->name);
        
        printf("\nEnter the item = ");
        gets(ptr->item);
        
        printf("\nEnter the price of item = ");
        scanf("%d", &ptr->price);
        
        ptr->next=NULL;

        if(head == NULL)
        {
            head = ptr;
        }

        else
        {
            temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
        }

        

    }
}

void delete()
{
    list *ptr, *temp;
    char nam[20];
    int val, flag;
    

    if(head == NULL)
    {
        printf("\n\nThere is no data present in the list to be deleted");
    }

    else 
    {
        if(head->next == NULL)
        {
            head = NULL;
            free(head);
            printf("\n\nThis was the last shop present in the list");
        }

        else
        {
            temp = head;
            fflush(stdin);
            printf("\n\nEnter the name of the shop to be deleted = ");
            gets(nam);

            while (temp->next != NULL)
            {
                val=strcmp(temp->next->name,nam);
                if(val==0)
                {
                    ptr = temp->next;
                    temp->next = ptr->next;
                    free(ptr);
                    printf("\n\nYou have remove the shop from the list");

                    flag=0;
                    break;
                }

                else
                {
                    flag=1;
                }
                
                temp = temp->next;
                
            }

            if(flag == 1)
            {
                printf("\n\nThere is no shop of such name present in the list");
            }
        }
    }
}

void view()
{
    list *ptr;
    char itm[20];
    int val, flag, c;
    
    ptr = head;
    
    if(ptr == NULL)
    {
        printf("\n\nThere is no shop data present in the list to display");
    }

    else
    {
        printf("\n\nPress 1 to show all present in the list\nPress 2 to show a specific item \n");
        
        scanf("%d",&c);

        if (c==1)
        {
            printf("\n\nThe list of the shops entered by user are");

            while(ptr != NULL)
            {
                printf("\n\nName of shop = %s", ptr->name);
                printf("\nProduct = %s",ptr->item);
                printf("\nPrice = %d",ptr->price);
                ptr = ptr->next;
            }
            
        }

        else if (c == 2)
        {
          fflush(stdin);
            printf("\nEnter the name of the item which you want to filter from others");
            printf("Item = ");
            gets(itm);

        
            printf("\n\nThe list of the shops entered by user are");
            while (ptr != NULL)
            {
                val=strcmp(ptr->item,itm);

                if(val==0)
                {
                    printf("\n\nName of shop = %s", ptr->name);
                    printf("\nProduct = %s",ptr->item);
                    printf("\nPrice = %d",ptr->price);
                    ptr = ptr->next;
                }

                else
                {
                    ptr = ptr->next;
                }
            }  
        }

        else
        {
            printf("\nThe entered choise is not valid\nPlease try again");
        }

        
    }

    
}

void sort()
{
    list *one, *two;
    int swap;
    char stk[100], stk1[100];
    
    for(one=head; one->next!=NULL; one=one->next)
    {
        for(two=one->next; two!=NULL; two=two->next)
        {
            if(one->price > two->price)
            {
                swap = one->price;
                one->price = two->price;
                two->price = swap;

                strcpy(stk, one->name);
                strcpy(one->name, two->name);
                strcpy(two->name, stk);

                strcpy(stk1, one->item);
                strcpy(one->item, two->item);
                strcpy(two->item, stk1);
            }
        }
    }
    printf("\n\nList is sorted by price");
    
}

void search ()
{
    list *ptr;
    int val, flag;
    char shop[20];
    
    ptr = head;
    if(ptr == NULL)
    {
        printf("\n\nThe list of the shops is empty");
    }

    else 
    {
        printf("\n\nEnter the name you want to search: ");
        scanf("%s", &shop);

        while(ptr!=NULL)
        {
            val=strcmp(ptr->name,shop);
            if(val==0)
            {
                printf("\n\nThe shop is %s is present in the list of shops",ptr->name);
                printf("\nThe price of %s = ", ptr->item);
                printf("%d",ptr->price);
                flag = 0;
                break;
            }
            else
            {
               flag=1;
               
            }
            ptr=ptr->next;
        }

        if(flag==1)
        {
            printf("\n\nThe shop does not exist in the list\nPlease check the name");
            
        }
    }
}
