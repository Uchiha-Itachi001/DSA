#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
    int ele;
    bool flag = false;
    printf("Enter the element to be searched: ");
    scanf("%d", &ele);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ele)
        {
            printf("The Element %d found at index : %d", ele, i + 1);
            flag = false;
            break;
        }
        else
        {
            flag = true;
        }
    }
    if (flag)
    {
        printf("The Element %d is  not found", ele);
    }

    return 0;
}