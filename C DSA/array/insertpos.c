#include<stdio.h>
#include<conio.h>
void main()
{
    int i,n,pos,num,arr[10];
    printf("Enter the number of elements in the array: \n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\n arr[%d]=",(i));
        scanf("%d",&arr[i]);
    }
    printf("\n Enter number to be inserted : ");
    scanf("%d",&num);
    printf("\n Enter position at which the number is to be added: ");
    scanf("%d",&pos);
    for(i=n-1;i>=pos;i--)
    arr[i+1]=arr[i];
    arr[pos]=num;
    n=n+1;
    printf("The array after insertion of %d is : ",num);
    for(i=0;i<n;i++)
    printf("\n arr[%d] = %d ",i,arr[i]);
}
