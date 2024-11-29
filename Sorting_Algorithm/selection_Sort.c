#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void Display(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void SelectionSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = INT_MAX;
        int min_index = -1;

        for (int j = i; j < n; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                min_index = j;
            }
        }

        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    int n;
    printf("Enter the size of the array : ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        printf("Enter the %d element : ", i);
        scanf("%d", &arr[i]);
    }

    printf("The Array Elements are : \n");
    Display(arr, n);
    
    SelectionSort(arr, n);
    printf("After Sorting the Array : \n");
    Display(arr, n);

    free(arr);
    return 0;
}

/*
   ::: OUTPUT :::

Enter the size of the array : 5
Enter the 0 element : 5
Enter the 1 element : 4
Enter the 2 element : 3
Enter the 3 element : 2
Enter the 4 element : 1
The Array Elements are :
5 4 3 2 1
After Sorting the Array :
1 2 3 4 5

*/