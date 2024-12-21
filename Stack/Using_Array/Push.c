#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int size;
    int top;
    int *arr;
} stack;

int isEmpty(stack *s);
void push(stack *s, int *few);
void Display(stack *s, int f);
int main()
{
    stack *s;
    s = (stack *)malloc(sizeof(stack)); // Initialize Stack

    printf("Enter the  Size of the Stack : ");
    scanf("%d", &s->size);

    s->arr = (int *)malloc(s->size * sizeof(int));
    s->top = -1;

    int few;
    printf("Enter the No. of element you Want To add Before Pop[Number <= %d] :", s->size);
    scanf("%d", &few);

    if (few > s->size)
    {
        printf("invalid Input\n");
        return 0;
    }

    // Adding Few elements , for Better Understanding
    for (int i = 0; i < few; i++)
    {
        printf("Enter the %d element : ", i);
        scanf("%d", &s->arr[i]);
        s->top++;
    }

    Display(s, few);

    printf("\n......Push Operations......\n");
    push(s, &few);  // PUSH operation 

    printf("\n......After Push Operations......\n");
    Display(s, few);

    return 0;
}

int isFull(stack *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    return 0;
}
void push(stack *s, int *f)
{
    if (!isFull(s))
    {   int element;
        printf("Enter the Element which You want to push : ");
        scanf("%d",&element);
        s->top++;
        s->arr[s->top] = element;        
        (*f)++;
    }
    else{
        printf("Sack Overflow\n Push Operation Can't Preform");
    }

}
void Display(stack *s, int f)
{
    if (f != 0)     //Chaking if there is  any element's are avalable or not
    {

        printf("\nTher stack Elements are ::\n");
        for (int i = 0; i < f; i++)
        {
            printf("%d ", s->arr[i]);
        }
        printf("\n");
    }
    else
    {
        printf("\nNo Element is Available");
    }
}

/*

  ::: OUTPUT :::
  
Enter the  Size of the Stack : 5
Enter the No. of element you Want To add Before Pop[Number <= 5] :3
Enter the 0 element : 1
Enter the 1 element : 2
Enter the 2 element : 3

Ther stack Elements are ::
1 2 3

......Push Operations......
Enter the Element which You want to push : 1020 

......After Push Operations......

Ther stack Elements are ::
1 2 3 1020
*/