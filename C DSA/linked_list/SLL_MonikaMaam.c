#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* start=NULL;

struct node* getnode()
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter Data :\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    return newnode;
}

void createlist(int n)
{
    int i;
    struct node* newnode;
    struct node* temp;
    for(i=0;i<n;i++)
    {
        newnode=getnode();
        if(start==NULL)
        start=newnode;
        else
        {
            temp=start;
            while (temp->next!=NULL)
            temp=temp->next;
            temp->next=newnode;
        }
    }
}

void insertAtBeg()
{
    struct node *newnode;
    newnode=getnode();
    if(start==NULL)
    {
        start=newnode;
    }
    else
    {
        newnode->next=start;
        start=newnode;
    }
}

void insertAtEnd()
{
    struct node *newnode,*temp;
    newnode=getnode();
    if(start==NULL)
    start=newnode;
    else
    {
        temp=start;
        while(temp->next!=NULL)
        temp=temp->next;
        temp->next=newnode;
    }
}

void insertAtMid()
{
    struct node *newnode,*temp,*prev;
    int pos,nodectr,ctr=1;
    newnode=getnode();
    printf("Enter the position : \n");
    scanf("%d\n",&pos);
    nodectr=countnode(start);
    if(pos>1 && pos<nodectr)
    {
        temp=prev=start;
        while(ctr < pos)
        {
            prev=temp;
            temp=temp->next;
            ctr++;
        }
        prev->next=newnode;
        newnode->next=temp;
    }
    else
    printf("position %d is not a middle position\n",pos);
}

int countnode(struct node *ptr)
{
    int ct=0;
    while(ptr!=NULL)
    {
        ct++;
        ptr=ptr->next;
    }
    return ct;
}

void deleteAtBeg()
{
    struct node* temp;
    if(start==NULL)
    printf("No Nodes Exist\n");
    else
    {
        temp=start;
        start=temp->next;
        free(temp);
        printf("Node Deleted\n");
    }
}

void deleteAtEnd()
{
    struct node *temp,*prev;
    if(start==NULL)
    {
        printf("Empty List\n");
    }
    else
    {
        temp=start;
        prev=start;
        while(temp->next!=NULL)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        free(temp);
        printf("Node Deleted\n");
    }
}

void deleteAtMid()
{
    int ctr=1,pos,nodectr;
    struct node *temp,*prev;
    if(start==NULL)
    {
        printf("Empty List\n");
    }
    else
    {
        printf("Enter position to be deleted : \n");
        scanf("%d",&pos);
        nodectr=countnode(start);
        if(pos>nodectr)
        {
            printf("\nThis node does not exist");
        }
        if(pos>1 && pos<nodectr)
        {
            temp=prev=start;
            while(ctr<pos)
            {
                prev=temp;
                temp=temp->next;
                ctr++;
            }
            prev->next=temp->next;
            free(temp);
            printf("Node Deleted \n");
        }
        else
        printf("\nInvalid position");
    }
}

void traverse()
{
    struct node *temp;
    temp=start;
    printf("Contents of the list\n");
    printf("--------------------------\n");
    if(start=NULL)
    printf("Empty List\n");
    else
    {
        while(temp!=NULL)
        {
            printf("%d -> ",temp->data);
            temp=temp->next;
        }
    }
    printf("X");
}

void main()
{
    int ch;
    do{
    printf("SINGLY LINKED LIST\n");
    printf("Menu\n");
    printf("1.Insert At Beginning\n");
    printf("2.Insert At a middle position\n");
    printf("3.Insert At End\n");
    printf("4.Delete At Beginning\n");
    printf("5.Delete At a middle position\n");
    printf("6.Delete At End\n");
    printf("7.Traverse List\n");
    printf("8.Exit");
    printf("Enter your choice : \n");
    scanf("%d\n",&ch);
    switch(ch)
    {
        case 1:insertAtBeg();
        break;
        case 2:insertAtEnd();
        break;
        case 3:insertAtMid();
        break;
        case 4:deleteAtBeg();
        break;
        case 5:deleteAtEnd();
        break;
        case 6:deleteAtMid();
        break;
        case 7:traverse();
        break;
        case 8:printf("Thank You!!\n");
        break;
        default:printf("Invalid Input");
    }
    }while(ch!=8);
}
