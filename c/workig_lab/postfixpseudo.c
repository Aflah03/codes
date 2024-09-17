#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
#include<string.h>

#define N 15

//stack 
typedef struct{
    char arr[N];
    int top;
}Stack;

int STACK_PUSH(Stack* S,char item){
    if(S->top == N-1 )
        return -1;
    else{
        S->top++;
        S->arr[S->top] = item;
        return 1;
    }

  }
char STACK_POP(Stack *S){
    if(S->top == -1){
        return 0;
    }
    else{
        char item = S->arr[S->top];
        S->top--;
        return item;
    }
}
bool Isempty(Stack *S){
    if(S->top ==-1) return true;
    
    return false;
}

bool Isoperand(char C){
    if(C >='0' && C<='9') return true;
    if(C >='a' && C<='z') return true;
    if(C >='A' && C<='Z') return true;
    return false;
}

bool Isoperator(char C){
    if( C== '+' || C == '-' ||  C == '*' || C=='/' || '^')
        return true;
    return false;
}

// Function to verify whether an operator is right associative or not. 
int IsRightAssociative(char op){
    if(op =='^')    return true;
    return false;
}
bool IsOpeningParentheses(char C){
    if( C == '(') return true;
    
    return false;
}
bool IsclosingParentheses(char C){
    if( C == ')') return true;
    
    return false;
}
int GetOperatorWeight(char op){
    int weight = -1;
    switch(op){
        case '+':
        case '-':
            weight=1;
            break;
        case '*':
        case '/':
            weight= 2;
            break;
        case '^':
            weight=3;
            break;
    }
    return weight;
}
int HasHigherPrecedence(char operator1,char operator2){

    int op1Weight = GetOperatorWeight(operator1);
    int op2Weight = GetOperatorWeight(operator2);

    // If operators have equal precedence, return true if they are left associative.
	// return false, if right associative.
	// if operator is left-associative, left one should be given priority.

    if(op1Weight ==op2Weight){

        if(IsRightAssociative(operator1)) return false;
        else return true;
    }
    return op1Weight > op2Weight? true: false;
}
int main(){
        Stack *S = (Stack*)malloc(sizeof(Stack));
        S->top = -1;
        // char expression[] ="23+50/5";
        char expression[100];
        printf("enter the expression: ");
        gets(expression);

        for(int i=0;i<strlen(expression);i++){
            if( expression[i] == ' '  || expression[i] ==',')
                continue;
            if(IsOpeningParentheses(expression[i])){
                STACK_PUSH(S,expression[i]);
                
            }
            else if(IsclosingParentheses(expression[i])){
                char x = STACK_POP(S);
                while(x!= '(' && !(Isempty(S))){
                    // printf("IS PARANTHESIS");
                    printf("%c ",x);
                    x = STACK_POP(S);
                }
            }
            else if(Isoperand(expression[i])){
                    while(Isoperand(expression[i])){
                    // printf("IS OPERAND");
                        printf("%c",expression[i]);
                        i++;
                    }
                    i--;
                    printf(" ");
            }
            else if(Isoperator(expression[i])){
                   while(!Isempty(S) && HasHigherPrecedence(S->arr[S->top], expression[i])) {
                     char x = STACK_POP(S);
                 printf("%c ", x);
                         }
                    STACK_PUSH(S, expression[i]);
            }
        }

        while(!Isempty(S)){
            char x = STACK_POP(S);
            printf("%c ",x);
        }
}
