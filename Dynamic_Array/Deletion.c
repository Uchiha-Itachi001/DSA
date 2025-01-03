#include <stdio.h>
#include <stdlib.h>

int Deletion(int *arr, int *n, int pos); // Deletion Function
void display(int *arr, int n); // Display Function
int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("The array Before Deletion: ");
    display(arr, n);

    int pos;
    printf("Enter the position at which the element is to be Delete [1 to %d]: ", n);
    scanf("%d", &pos);

    if (pos > n)
    {
        printf("Invalid Position");
    }
    else
    {
        printf("The element deleted is %d\n", Deletion(arr, &n, pos - 1));

        printf("The array After Deletion: ");
        display(arr, n);
    }

    free(arr);
    return 0;
}

int Deletion(int *arr, int *n, int pos)
{
    int ele = arr[pos];
    for (int i = pos; i < *n; i++)
    {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    return ele;
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
Enter the element 1: 1
Enter the element 2: 2
Enter the element 3: 3
Enter the element 4: 4
Enter the element 5: 5
The array Before Deletion: 1 2 3 4 5
Enter the position at which the element is to be Delete [1 to 5]: 3
The element deleted is 3
The array After Deletion: 1 2 4 5
*/