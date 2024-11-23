#include <stdio.h>
#include <stdlib.h>

void display(int *arr, int n);
int main()
{
    int *arr = (int *)malloc(10 * sizeof(int));
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Before sorting: \n");
    display(arr, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("After sorting: \n");
    display(arr, n);

    return 0;
}
void display(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/*
    ::: Output :::

    Enter the size of the array: 5
    Enter element 1: 5
    Enter element 2: 4
    Enter element 3: 3
    Enter element 4: 2
    Enter element 5: 1
    Before sorting:
    5 4 3 2 1
    After sorting:
    1 2 3 4 5

*/