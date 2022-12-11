/* C Program to implement circular queue using arrays  */

#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int cqueue_arr[MAX];
int front=-1;
int rear=-1;

void display( );
void insert(int item);
int del();
int peek();
int isEmpty();
int isFull();

int main()
{
        int choice,item;
        while(1)
        {
                printf("\n1.Insert\n");
                printf("2.Delete\n");
                printf("3.Peek\n");
                printf("4.Display\n");
                printf("5.Quit\n");
                printf("\nEnter your choice : ");
                scanf("%d",&choice);

                switch(choice)
                {
                case 1 :
                        printf("\nInput the element for insertion : ");
                        scanf("%d",&item);
                        insert(item);
                        break;
                case 2 :
                        printf("\nElement deleted is : %d\n",del());
                        break;
                case 3:
                        printf("\nElement at the front is  : %d\n",peek());
                        break;
                case 4:
                        display();
                        break;
                case 5:
                        exit(1);
                default:
                        printf("\nWrong choice\n");
                }/*End of switch*/
        }/*End of while */

        return 0;

}/*End of main()*/

void insert(int item)
{
        if( isFull() )
        {
                printf("\nQueue Overflow\n");
                return;
        }
        if(front == -1 )
                front=0;

        if(rear==MAX-1)/*rear is at last position of queue*/
                rear=0;
        else
                rear=rear+1;
        cqueue_arr[rear]=item ;
}/*End of insert()*/

int del()
{
        int item;
        if( isEmpty() )
        {
                printf("\nQueue Underflow\n");
                exit(1);
        }
        item=cqueue_arr[front];
        if(front==rear) /* queue has only one element */
        {
                front=-1;
                rear=-1;
        }
        else if(front==MAX-1)
                front=0;
        else
                front=front+1;
        return item;
}/*End of del() */

int isEmpty()
{
        if(front==-1)
                return 1;
        else
                return 0;
}/*End of isEmpty()*/

int isFull()
{
        if((front==0 && rear==MAX-1) || (front==rear+1))
                return 1;
        else
                return 0;
}/*End of isFull()*/

int peek()
{
        if( isEmpty() )
        {
                printf("\nQueue Underflow\n");
                exit(1);
        }
        return cqueue_arr[front];
}/*End of peek()*/

void display()
{
        int i;
        if(isEmpty())
        {
                printf("\nQueue is empty\n");
                return;
        }
        printf("\nQueue elements :\n");
        i=front;
        if( front<=rear )
        {
                while(i<=rear)
                        printf("%d ",cqueue_arr[i++]);
        }
        else
        {
                while(i<=MAX-1)
                        printf("%d ",cqueue_arr[i++]);
                i=0;
                while(i<=rear)
                        printf("%d ",cqueue_arr[i++]);
        }
        printf("\n");
}/*End of display() */
