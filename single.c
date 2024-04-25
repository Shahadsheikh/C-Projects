
#include<stdlib.h>
#include<stdio.h>

struct node
{
        int info;
        struct node *next;
}*first,*last,*temp;

void freenode(struct node *p)
{
        free(p);
}

void getnode()
{
        temp=(struct node*)malloc(sizeof(struct node));
        printf("Element to be inserted:");
        scanf("%d",&temp->info);
        temp->next=NULL;
}

void insertbeg()
{
        if(first==NULL)
        {
                getnode();
                first=temp;
                last=first;
        }
        else
        {
                getnode();
                temp->next=first;
                first=temp;
        }
}

void insertend()
{
        if(first==NULL)
        {
                getnode();
                first=temp;
                last=first;
        }
        else
        {
                getnode();
                last->next=temp;
                last=temp;
        }
}

void insertpos()
{
        int pos,i=1;
        struct node *temp1;
        temp1=first;
        printf("Enter the position:");
        scanf("%d",&pos);
        getnode();
        while(i<pos)
        {
                temp1=temp1->next;
                i--;
        }
        temp->next=temp1->next;
        temp1->next=temp;
}

void deletebeg()
{
        struct node *temp;
        temp=first;
        if(first==NULL)
        {
                printf("Deleted element is %d",temp->info);
                freenode(temp);
                first=last=NULL;
                return;
        }
        else
        {
                first=temp->next;
                printf("Deleted element is%d",temp->info);
                freenode(temp);
        }
}


void deleteEnd()
{
        struct node*temp;
        temp=first;
        if(first==NULL)
        {
                printf("List is empty");
                return;
        }
        else if(temp->next==NULL)
        {
                printf("Deleted element is %d",temp->info);
                freenode(temp);
                first=last=NULL;
                return;
        }
        else
        {
                while(temp->next!=last)
                {
                        temp=temp->next;
                }
        }
        printf("Deleted element is %d",last->info);
        freenode(last);
        last=temp;
        temp->next=NULL;
}

void deleteele()
{
    int ele;
    struct node *temp,*temp1,*nextnode,*head;
    temp=first;
    head->next=first;
    temp1=head;
    printf("Enter the element to be deleted:");
    scanf("%d",ele);
    while(ele!=temp->info)
    {
        temp=temp->next;
        temp1=temp1->next;
     }
    {
        nextnode=temp1->next;
        temp1->next=temp->next;
        freenode(nextnode);
    }
}
void display()
{
        struct node *temp1;
        temp1=first;
        if(temp1==NULL)
        {
                printf("List is empty");
                return;
        }
        else
        {
                printf("Elements in list are:");
                while(temp1!=NULL)
                {
                        printf("%d\t",temp1->info);
                        temp1=temp1->next;
                }
        }
}

void main()
{
        int ch;
        do
        {
                printf("\n 1.Insert at begining \n 2.Insert at End \n 3.Insert at Position \n 4.Delete from front \n 5.Delete from end \n 6.Delete from given position \n 7.Display \n 8.Exit");
                printf("\n Enter your choice:");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1: insertbeg();
                                break;
                        case 2: insertend();
                                break;
                        case 3: insertpos();
                                break;
                        case 4: deletebeg();
                                break;
                        case 5: deleteEnd();
                                break;
                        case 6: deleteele();
                                break; 
                        case 7: display();
                                break;
                        case 8: exit(0);
                        default:printf("Invalid Choice!!");
                                break;
                }
        }while(ch<=7);
}





        


