#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
    int coeff;
    int ppow;
    struct node *next;
};
struct node *insert(struct node*head,int data,int p)
{
    struct node *temp;
    struct node *newp=(struct node*)malloc(sizeof(struct node));
    newp->coeff=data;
    newp->ppow=p;
    newp->next=NULL;
    if(head==NULL || p>head->ppow)
    {
        newp->next=head;
        head=newp;
    }
    else
    {
        temp=head;
        while(temp->next != NULL && temp->next->coeff >= p)
        {
            temp=temp->next;
        }
        newp->next=temp->next;
        temp->next=newp;
    }
    //printf("%d%d",newp->coeff,newp->ppow);
    return head;
}
void printbegin(struct node* head)
{
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d(x^%d)+",temp->coeff,temp->ppow);
        temp=temp->next;
    }
}
void add(struct node *head1,struct node *head2)
{
    struct node *ptr1=head1;
    struct node *ptr2=head2;
    struct node *head3=NULL;
    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->ppow == ptr2->ppow)
        {
            head3=insert(head3,ptr1->coeff + ptr2->coeff,ptr1->ppow);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        else
        if(ptr1->ppow > ptr2->ppow)
        {
            head3=insert(head3, ptr1->coeff,ptr1->ppow);
            ptr1=ptr1->next;
        }
        else
        if(ptr1->ppow < ptr2->ppow)
        {
            head3=insert(head3, ptr2->coeff,ptr2->ppow);
            ptr2=ptr2->next;
        }
    }
    while(ptr1 != NULL)
    {
        head3=insert(head3,ptr1->coeff,ptr1->ppow);
        ptr1=ptr1->next;
    }
    while(ptr2 != NULL)
    {
        head3=insert(head3,ptr2->coeff,ptr2->ppow);
        ptr2=ptr2->next;
    }
    printf("Addition of Polynomials\n");
    printbegin(head3);
    printf("\n");
}

void sub(struct node *head1,struct node *head2)
{
    struct node *ptr1=head1;
    struct node *ptr2=head2;
    struct node *head3=NULL;
    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->ppow == ptr2->ppow)
        {
            head3=insert(head3,ptr1->coeff - ptr2->coeff,ptr1->ppow);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        else
        if(ptr1->ppow > ptr2->ppow)
        {
            head3=insert(head3, ptr1->coeff,ptr1->ppow);
            ptr1=ptr1->next;
        }
        else
        if(ptr1->ppow < ptr2->ppow)
        {
            head3=insert(head3, ptr2->coeff,ptr2->ppow);
            ptr2=ptr2->next;
        }
    }
    while(ptr1 != NULL)
    {
        head3=insert(head3,ptr1->coeff,ptr1->ppow);
        ptr1=ptr1->next;
    }
    while(ptr2 != NULL)
    {
        head3=insert(head3,ptr2->coeff,ptr2->ppow);
        ptr2=ptr2->next;
    }
    printf("Subtraction of Polynomials\n");
    printbegin(head3);
    printf("\n");
}


void multiply(head1,head2)
{
    struct node *ptr1=head1;
    struct node *ptr2=head2;
    struct node *head3=NULL;
    int res1,res2;
    if(ptr1==NULL ||ptr2==NULL)
    {
        printf("The polynomials cannot be multiplied \n");
    }
    else
    {
        while(ptr1!=NULL)
        {
            ptr2=head2;
            while(ptr2!=NULL)
            {
                res1=ptr1->coeff * ptr2->coeff;
                res2=ptr1->ppow + ptr2->ppow;
                head3=insert(head3,res1,res2);
                ptr2=ptr2->next;
            }
            ptr1=ptr1->next;
        }
    }
    printf("\nMultiplication of Polynomials\n");
    printbegin(head3);
    printf("\n");
}
void main()
{
    struct node *head1,*head2;
    head1=NULL;
    head2=NULL;
    int ch,max1,i,p,max2,c;
    do
    {
        printf("---------------MAIN MENU-----------------\n");
        printf("1.Input Polynomials\n");
        printf("2.View Polynomials\n");
        printf("3.Addition of Polynomials\n");
        printf("4.Subtraction of Polynomials\n");
        printf("5.Multiplication of Polynomials\n");
        printf("6.Exit\n");
        printf("Enter your choice : \n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter maximum terms of polynomial 1 \n");
            scanf("%d",&max1);
            for(i=0;i<max1;i++)
            {
                printf("Enter the power \n");
                scanf("%d",&p);
                printf("Enter the coefficient \n");
                scanf("%d",&c);
                head1=insert(head1,c,p);
            }
            printf("Enter maximum terms of polynomial 2 \n");
            scanf("%d",&max2);
            for(i=0;i<max2;i++)
            {
                printf("Enter the power \n");
                scanf("%d",&p);
                printf("Enter the coefficient \n");
                scanf("%d",&c);
                head2=insert(head2,c,p);
            }
            break;

            case 2:printf("Polynomial 1\n");
            printbegin(head1);
            printf("\n");
            printf("Polynomial 2\n");
            printbegin(head2);
            printf("\n");
            break;

            case 3:add(head1,head2);
            break;

            case 4:sub(head1,head2);
            break;

            case 5:multiply(head1,head2);
            break;

            case 6:printf("Thank You! \n");
            break;

            default:printf("Invalid Input\n");
        }
    }while(ch!=6);
}
