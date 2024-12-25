#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
    int size;
    int top;
    char *arr;
} stack;

int isEmpty(stack *s);
int isFull(stack *s);
int pop(stack *s);
void push(stack *s, char ch);
int Pre(char ch);
int operator(char ch);
char stackTop(stack *s);
void InfixToPostfix(char *infix);

int main(){
    char infix[100];
    printf("Enter The Infix Expression: ");
    fgets(infix, 100, stdin);
    infix[strcspn(infix, "\n")] = '\0'; // Remove trailing newline

    InfixToPostfix(infix);

    return 0;
}


int isEmpty(stack *s){
    return s->top < 0;
}

int isFull(stack *s){
    return s->top == s->size - 1;
}

int pop(stack *s){
    if (!isEmpty(s)){
        char p = s->arr[s->top];
        s->top--;
        return p;
    }
    return -1;
}

void push(stack *s, char ch){
    if (!isFull(s)){
        s->top++;
        s->arr[s->top] = ch;
    }
}

int Pre(char ch){
    if (ch == '+' || ch == '-'){
        return 1;
    }
    if (ch == '*' || ch == '/'){
        return 2;
    }
    return 0;
}

int operator(char ch){
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/'){
        return 1;
    }
    return 0;
}

char stackTop(stack *s){
    return s->arr[s->top];
}

void InfixToPostfix(char *infix){
    int length = strlen(infix);
    stack *s = (stack *)malloc(sizeof(stack));
    s->size = length;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));
    char *postfix = (char *)malloc((length + 1) * sizeof(char));
    int i = 0, j = 0;
    while (infix[i] != '\0'){
        if (!operator(infix[i]) && infix[i] != '(' && infix[i] != ')'){
            postfix[j++] = infix[i++];
        }
        else if (infix[i] == '('){
            push(s, infix[i++]);
        }
        else if (infix[i] == ')'){
            while (!isEmpty(s) && stackTop(s) != '('){
                postfix[j++] = pop(s);
            }
            pop(s); // Remove '(' from stack
            i++;
        }
        else{
            while (!isEmpty(s) && Pre(infix[i]) <= Pre(stackTop(s))){
                postfix[j++] = pop(s);
            }
            push(s, infix[i++]);
        }
    }
    while (!isEmpty(s)){
        postfix[j++] = pop(s);
    }
    postfix[j] = '\0';

    printf("The Postfix Expression is : %c\n", postfix[0]);
    printf("The Postfix Expression is : %s", postfix);
    free(s->arr);
    free(s);
    free(postfix);
}

/*

::::OUTPUT::::

Enter The Infix Expression: 5*(12+1)
The Postfix Expression is : 5121+*
*/