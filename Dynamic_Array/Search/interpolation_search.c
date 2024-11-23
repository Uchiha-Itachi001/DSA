#include<stdio.h>
#include<stdlib.h>

void Interpolation(int *arr,int n);
int main()
{
    int n;
    int *arr = (int*)malloc(10*sizeof(int));    
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    printf("Enter the elements of the Sorted-array:\n");// To use binary search the array must be sorted
    for(int i=0;i<n;i++){
        printf("Enter the element %d : ",i);
        scanf("%d",&arr[i]);
    }

    Interpolation(arr,n);

    return 0;
}

void Interpolation(int *arr,int n){
    int ele;
    printf("Enter the element to be searched: ");
    scanf("%d",&ele);
    int low =0,high = n-1;
    while(low<=high){
        int mid = low +((ele - arr[low])/(arr[high]-arr[low]))*(high-low);

        if(arr[mid]==ele){
            printf("Element found at index %d\n",mid);
            return ;
        }
        else if(arr[mid]>ele){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    if(low>high){
        printf("Element not found\n");
    }
}

/*
    ::: Output :::

    Enter the size of the array: 5
    Enter the elements of the Sorted-array:     
    Enter the element 0 : 1
    Enter the element 1 : 2
    Enter the element 2 : 3
    Enter the element 3 : 4
    Enter the element 4 : 5
    Enter the element to be searched: 4
    Element found at index 3

*/