#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int size;
    int top;
    int *arr;
} stack;

int isEmpty(stack *s);
int isFull(stack *s);
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
    printf("Enter the No. of element you Want To add Before Push or Pop[Number <= %d] :", s->size);
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

    printf("\n ..........Operation....... \n");
    if (isEmpty(s))
    {
        printf("Stack UnderFlow\n");
        printf("You Can perform Push Operation");
    }
    else if (isFull(s))
    {
        printf("Stack OverFlow\n");
        printf("You Can perform Pop Operation");
    }
    else
    {
        printf("You Can perform Push and Pop Operation");
    }

    return 0;
}
int isEmpty(stack *s)
{
    if (s->top < 0)
    {
        return 1;
    }
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
void Display(stack *s, int f)
{
    printf("Ther stack Elements are ::\n");
    for (int i = 0; i < f; i++)
    {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

/*
    :::OUTPUT:::

(----- Case:1 -----)
Enter the  Size of the Stack : 5
Enter the No. of element you Want To add Before Push or Pop[Number <= 5] :5
Enter the 0 element : 1
Enter the 1 element : 2
Enter the 2 element : 3
Enter the 3 element : 4
Enter the 4 element : 5
Ther stack Elements are ::
1 2 3 4 5

 ..........Operation.......
Stack OverFlow
You Can perform Pop Operation

(----- Case:2 -----)
Enter the  Size of the Stack : 5
Enter the No. of element you Want To add Before Push or Pop[Number <= 5] :2
Enter the 0 element : 1
Enter the 1 element : 2
Ther stack Elements are ::
1 2

 ..........Operation.......
You Can perform Push and Pop Operation

(----- Case:3 -----)
Enter the  Size of the Stack : 5
Enter the No. of element you Want To add Before Push or Pop[Number <= 5] :0
Ther stack Elements are ::


 ..........Operation.......
Stack UnderFlow
You Can perform Push Operation

*/