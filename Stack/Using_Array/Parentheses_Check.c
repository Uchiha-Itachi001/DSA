#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct stack
{
    int size;
    int top;
    char *arr;
}stack;

int isEmpty(stack *s);
int isFull(stack *s);
void push (stack *s,char par);
char pop(stack *s);
int PairMatch(char open,char close);
int ParenthesesCheck(char *str);

int main()
{
   char Exp[100];
   printf("Enter an expression: ");
   gets(Exp);

   if(ParenthesesCheck(Exp)){
    printf("%s has Balance Parantheses",Exp);
   }
   else{
    printf("%s has Unbalance Parantheses",Exp);
   }

    return 0;
}

int isEmpty(stack *s){
    if(s->top <0){
        return 1;
    }
    return 0;
}
int isFull(stack *s){
    if(s->top == s->size-1){
        return 1;
    }
    return 0;
}

void push (stack *s,char par){
    if(!isFull(s)){
        s->top++;
        s->arr[s->top] =par;
    }
    return;
}
char pop(stack *s){
    if(!isEmpty(s)){
        char pre = s->arr[s->top];
        s->top--;
        return pre;
    }
    return -1;
}

//......Checking The stack Top parentheses With Expresion's parentheses
int PairMatch(char open,char close){
    if((open == '(' && close == ')' )||(open == '{' && close == '}' )||(open == '[' && close == ']' )){
        return 1;
    }
    return 0;
}

//......Checking For Balance parentheses
int ParenthesesCheck(char *str){
    int stackSize = strlen(str);

    //.....Initialise Stack 
    stack *p = (stack*)malloc(sizeof(stack));
    p->size = stackSize;
    p->top = -1;
    p->arr = (char*)malloc(stackSize * sizeof(char));

    //....Iterate Through  Every Character Of the Expression from Left to Right
   for(int i=0;str[i]!='\0';i++){

    if(str[i]=='('||str[i]=='{'||str[i]=='['){ //...push The opening parentheses to the stack
        push(p,str[i]);
    }

    else if(str[i]==')'||str[i]=='}'||str[i]==']'){ //...pop The opening parentheses to the stack
        if(isEmpty(p)){
           return 0; 
        }
        char pre = pop(p);
        if(!PairMatch(pre,str[i])){
            return 0;
        }
    }
   }

   int result = isEmpty(p);   //......After Going through Every Element. If the Stack is not Empty means parentheses is not Balance
    return result;
}


/*
:::OUTPUT:::
Enter an expression: [1+{23-(4+23)}]
[1+{23-(4+23)}] has Balance Parantheses

*/