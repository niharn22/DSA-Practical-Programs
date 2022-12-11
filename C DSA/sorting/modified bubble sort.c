#include<stdio.h>

void printArray(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
}

void bubbleSort(int *a,int n)
{
    int temp;
    int issorted=0;
    for(int i=0;i<n-1;i++)
    {
        printf("\nWorking on pass number %d\n",i+1);
        issorted=1;
        for(int j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                issorted=0;
            }
        }
        if(issorted)
            return;
    }
}

int main()
{
    int a[]={12,54,65,7,23,9};
    int n=6;
    printf("Original Array\n");
    printArray(a,n);
    bubbleSort(a,n);
    printf("\nSorted Array\n");
    printArray(a,n);
    return 0;
}

