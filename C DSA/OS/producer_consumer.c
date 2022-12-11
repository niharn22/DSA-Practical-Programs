#include<stdio.h>
#include<stdlib.h>

int mutex=1,full=0,empty=10,x=0;
void producer()
{
    --mutex;
    ++full;
    --empty;
    x++;
    printf("\nProducer produces item %d",x);
    ++mutex;
}
void consumer()
{
    --mutex;
    --full;
    ++empty;
    printf("\nConsumer consumes item %d",x);
    x--;
    ++mutex;
}
void main()
{
    int i,ch;
    printf("\n1.Producer\n2.Consumer\n3.Exit\nEnter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:if((mutex==1)&&(empty!=0))
        producer();
        else
        printf("\nBuffer is Full");
        break;
        case 2:if((mutex==1)&&(empty!=0))
        consumer();
        else
        printf("\nBuffer is Empty");
        break;
        case 3:printf("Thank You!!");
        break;
    }
}