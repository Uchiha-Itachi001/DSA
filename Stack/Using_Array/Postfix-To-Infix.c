/*
---- 
Limitation of this code it take 
only single digit number 1,2,3 not 10,12
Remember that , if we modify this code for 2 digits, it become more complex...
----
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
    int size;
    int top;
    char **arr;
} stack;

int isEmpty(stack *s);
int isFull(stack *s);
char *pop(stack *s);
void push(stack *s, char *str);
int operator(char ch);
void PostfixToInfix(char *postfix);

int main(){
    char postfix[100];
    printf("Enter The Postfix Expression: ");
    gets(postfix);
    
    PostfixToInfix(postfix);

    return 0;
}

int isEmpty(stack *s){
    return s->top < 0;
}

int isFull(stack *s){
    return s->top == s->size - 1;
}

char *pop(stack *s){
    if (!isEmpty(s)){
        char *p = s->arr[s->top];
        s->top--;
        return p;
    }
    return NULL;
}

void push(stack *s, char *str){
    if (!isFull(s)){
        s->top++;
        s->arr[s->top] = str;
    }
}

int operator(char ch){
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/'){
        return 1;
    }
    return 0;
}

void PostfixToInfix(char *postfix){
    int length = strlen(postfix);
    stack *s = (stack *)malloc(sizeof(stack));
    s->size = length;
    s->top = -1;
    s->arr = (char **)malloc(s->size * sizeof(char *));
    int i = 0;
    while (postfix[i] != '\0'){
        if (!operator(postfix[i])){
            char *operand = (char *)malloc(2 * sizeof(char));
            operand[0] = postfix[i];
            operand[1] = '\0';
            push(s, operand);
        }
        else{
            char *op2 = pop(s);
            char *op1 = pop(s);
            int newSize = strlen(op1) + strlen(op2) + 4;
            char *expr = (char *)malloc(newSize * sizeof(char));
            snprintf(expr, newSize, "(%s%c%s)", op1, postfix[i], op2);
            push(s, expr);
            free(op1);
            free(op2);
        }
        i++;
    }
    char *infix = pop(s);
    printf("The Infix Expression is : %s\n", infix);
    free(infix);
    free(s->arr);
    free(s);
}
/*

::::OUTPUT ::::

Enter The Postfix Expression: 23+5+
The Infix Expression is : ((2+3)+5)

  */