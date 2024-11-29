#include<stdio.h>
#include<stdlib.h>
int main()
{
    int row,col;
    printf("Enter the number of rows:");
    scanf("%d",&row);
    printf("Enter the number of columns:");
    scanf("%d",&col);
    
    int **arr=(int **)malloc(row*sizeof(int));
    for(int i=0;i<row;i++){
        arr[i] = (int*)malloc(col*sizeof(int));
    }
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("Enter element [%d][%d]:",i,j);
            scanf("%d",&arr[i][j]);
            
        }
    }
    int count=0;
    //Count the non-Zero Elements 
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j]!=0){
                count++;
            }
        }
    }
    printf("Number of non-zero elements in the matrix is: %d",count);
    printf("\n");


    // Sparse Matrix Create 
    int **sparse=(int **)malloc((count+1)*sizeof(int));
    for(int i=0;i<=count;i++){
        sparse[i]=(int*)malloc(3*sizeof(int));  
    }

    // Sparse Matrix Logic

    printf("The Sparse Matrix is :: \n");
    int k=0;
    if(k==0){
        sparse[k][0]=row;
        sparse[k][1]=col;
        sparse[k][2]=count;
        k++;
    }
  
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j]!=0){
                sparse[k][0]=i;
                sparse[k][1]=j;
                sparse[k][2]=arr[i][j];
                k++;
            }
        }
    }




    for(int i=0;i<=count;i++){
        for(int j=0;j<3;j++){
            printf("%d ",sparse[i][j]);
        }
        printf("\n");
    }

for(int i=0;i<row;i++){
    free(sparse[i]);
}
free(sparse);
for(int i=0;i<row;i++){
    free(arr[i]);
}
free(arr);

    return 0;
}

/*
 ::: OUTPUT :::

Enter the number of rows:3
Enter the number of columns:3
Enter element [0][0]:1
Enter element [0][1]:2
Enter element [0][2]:3
Enter element [1][0]:0
Enter element [1][1]:0
Enter element [1][2]:0
Enter element [2][0]:0
Enter element [2][1]:0
Enter element [2][2]:0
Number of non-zero elements in the matrix is: 3   
The Sparse Matrix is ::
3 3 3
0 0 1
0 1 2
0 2 3

*/