#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start=NULL;
struct node *display(struct node *);
struct node *insert_beg(struct node *);

int main()
{
    int ch;
    do
    {
        printf("------------------MAIN MENU-----------------\n");
        printf("1.Create List\n");
        printf("2.Display List\n");
        printf("3.Add a node in beginning\n");
        printf("4.Add a node in end\n");
        printf("5.Add a node after a node\n");
        printf("6.Delete a node in beginning\n");
        printf("7.Delete a node in the end\n");
        printf("8.Delete a node after a given node\n");
        printf("9.Exit\n");
        printf("Enter your choice : \n");
        scanf("%d\n",&ch);
        switch(ch)
        {
            case 2:start=display(start);
            break;
            case 3:start=insert_beg(start);
            break;
            case 4:start=insert_end(start);
            break;
            case 5:start=insert_mid(start);
            break;
            case 6:start=delete_start(start);
            break;
            case 7:start=delete_end(start);
            break;
            case 8:start=delete_mid(start);
            break;
            case 9:printf("Thank You\n");
            break;
            default:printf("Invalid Input\n");
        }
    }while(ch!=9);
    getch();
    return 0;
}

struct node *display(struct node *start)
{
    struct node *ptr;
    ptr=start;
    while(ptr!=NULL)
    {
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }
    return start;
}

struct node *insert_beg(struct node *start)
{
    struct node *new_node;
    int num;
    printf("Enter the data : \n");
    scanf("%d\n",&num);
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=num;
    new_node->next=start;
    start=new_node;
    return start;
};
