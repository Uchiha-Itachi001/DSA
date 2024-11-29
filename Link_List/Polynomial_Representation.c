#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    int exponent;
    struct Node *next;
} node;

int main()
{
    int n;
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &n);
    node *head, *temp, *new;
    head = (node *)malloc(sizeof(node));
    printf("Enter the 1 cofficient : ");
    scanf("%d", &head->data);
    printf("Enter the exponent : ");
    scanf("%d", &head->exponent);

    head->next = NULL;
    temp = head;
    for (int i = 2; i <= n; i++)
    {
        new = (node *)malloc(sizeof(node));
        printf("Enter the %d cofficient : ", i);
        scanf("%d", &new->data);
        printf("Enter the exponent : ");
        scanf("%d", &new->exponent);
        new->next = NULL;
        temp->next = new;
        temp = new;
    }

    // Polynomial
    temp = head;
    for (int i = 1; i <= n; i++)
    {
        if (i == n)
        {
            printf("(%d*X^%d)\n", temp->data, temp->exponent);
        }
        else
        {
            printf("(%d*X^%d)+", temp->data, temp->exponent);
        }
        temp = temp->next;
    }

    temp = head;
    int polynomial;
    printf("Enter The value of polynomial : ");
    scanf("%d", &polynomial);
    int sum = 0;
    while (temp != NULL)
    {
        sum += temp->data * pow(polynomial, (temp->exponent));
        temp = temp->next;
    }
    printf("The value of polynomial is : %d\n", sum);

    return 0;
}

/*
 ::: OUTPUT :::

Enter the number of terms in the polynomial: 4
Enter the 1 cofficient : 5
Enter the exponent : 3
Enter the 2 cofficient : 2
Enter the exponent : 2
Enter the 3 cofficient : -3
Enter the exponent : 1
Enter the 4 cofficient : 6
Enter the exponent : 0
(5*X^3)+(2*X^2)+(-3*X^1)+(6*X^0)
Enter The value of polynomial : 2
The value of polynomial is : 48
*/