#include <stdio.h>
#include <stdlib.h>
void BinarySearch(int *arr, int n);
int main()
{

    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements of the Sorted-array:\n"); // To use binary search the array must be sorted
    for (int i = 0; i < n; i++)
    {
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    BinarySearch(arr, n);

    return 0;
}
void BinarySearch(int *arr, int n)
{
    int ele;
    printf("Enter the element to be searched: ");
    scanf("%d", &ele);
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == ele)
        {
            printf("The Element %d is present at index %d\n", ele, mid);
            break;
        }
        else if (arr[mid] < ele)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (low > high)
    {
        printf("The Element %d is not present in the array\n", ele);
    }
}

/*
::: Output :::

Enter the size of the array: 5
Enter the elements of the Sorted-array:     
Enter the element 1: 1
Enter the element 2: 2
Enter the element 3: 3
Enter the element 4: 4
Enter the element 5: 5
Enter the element to be searched: 2
The Element 2 is present at index 1

*/