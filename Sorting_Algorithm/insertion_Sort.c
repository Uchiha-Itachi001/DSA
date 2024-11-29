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

void InsertionSort(int *arr,int n){
    for(int i=1;i<n;i++){
        int j=i;
        while (j>0 && arr[j]<arr[j-1]){
            int  temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
            j--;
        }
        
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
    
    InsertionSort(arr, n);
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