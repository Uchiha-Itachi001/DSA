#include <stdio.h>
#include <stdlib.h>

void insertion(int *arr, int *n, int pos);
void display(int *arr, int n);
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
    printf("The array Before Insertion: ");
    display(arr, n);
    int pos;
    printf("Enter the position at which the element is to be inserted [1 to %d]: ", n);
    scanf("%d", &pos);
    if (pos > n)
    {
        printf("Invalid Position");
    }
    else
    {
        insertion(arr, &n, pos - 1);
        printf("The array After Insertion: ");
        display(arr, n);
    }

    free(arr);
    return 0;
}

void insertion(int *arr, int *n, int pos)
{
    int ele;
    printf("Enter the element to be inserted: ");
    scanf("%d", &ele);
    for (int i = *n; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos] = ele;
    (*n)++;
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
The array Before Insertion: 1 2 3 4 5       
Enter the position at which the element is to be inserted [1 to 5]: 2
Enter the element to be inserted: 100
The array After Insertion: 1 100 2 3 4 5 
*/