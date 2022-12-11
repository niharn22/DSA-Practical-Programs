#include <stdio.h>
void swap(int *a, int *b)
{
    *a=*a + *b;
    *b=*a - *b;
    *a=*a - *b;
    return ;
}

// Function definition of sort array using shell sort
void shellsort(int arr[], int nums)
{
    // i -> gap/interval
    for (int i = nums / 2; i > 0; i = i / 2)
    {
        // Traverse j till we reach the end of the sublist.
        for (int j = i; j < nums; j++)
        {
            for(int k = j - i; k >= 0; k = k - i)
            {
                if (arr[k+i] >= arr[k])
                {
                    break;
                }
                else
                {
                    swap(&arr[k], &arr[k+i]);
                }
            }
        }
    }
    return ;
}

int main()
{
    int nums;
    printf("Enter total no. of elements :: ");
    scanf("%d", &nums);
    int arr[nums];
    printf("Enter the array:: \n");
    //scan the array elements.
    for (int k =  0 ; k < nums; k++)
    {
                scanf("%d", &arr[k]);
    }

    //Call the function of shell sort, bypassing the array base pointer to the first element.
    shellsort(arr, nums);

    // After the sorting the array is
    printf("Sorted array is:  \n");
    for (int k = 0; k < nums; k++)
    {
        printf("%d ", arr[k]);
    }
    return 0;
}
