#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
#include<string.h>

#define N 15

/********************************************************************************************************************************
*                                                                                                                               *
*                                                                                                                               *
*                                                                                                                               *
*                                                                                                                                 *
*      how to make this code
    Infix to Postfix Conversion
    Initialize a stack of characters to hold the operators (^, *, /, +, -)
    • Parse the infix string left to right:
    If an operand is read:
    • Then output it into the postfix expression expression
    Else if ‘(‘ is read
    • Then push it into the stack
    • Else if E ‘)’ is read:
    • Then pop and output into the postfix expression until matching ‘(‘ is popped from the stack
    • Else if an operator Xis read:
    • If the stack is empty or character Y(top of the stack) = ‘(‘ or Yis an operator of lower precedence than X, then push X
    • While Y is an operator of higher or equal precedence than X, pop and output Y
    • Then push X
    • When we reach the end of input, pop and output until stack is empty                                                                                                                         *
*                                                                                                                               *
*                                                                                                                               *
*********************************************************************************************************************************/

//stack 
typedef struct{
    char arr[N];
    int top;
}Stack;

int STACK_PUSH(Stack* S,char item){
    if(S->top == N-1 ) //  (*S).top 
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
        return 1;
    }
}
bool Isempty(Stack *S){
    if(S->top ==-1) return true;
    
    return false;
}
bool IsclosingParentheses(char C);
bool IsOpeningParentheses(char C);
//function to verify whether an operator has higher precedence or not.
int HasHigherPrecedence(char operator1,char operator2);


// Function to verify whether a character is operator symbol or not. 
bool Isoperator(char C);

//Function to verify whether a character is alphanumeric character or not(letter or digit) or not.
bool Isoperand(char C);


//MAIN
int main(){
    Stack *S = (Stack*)malloc(sizeof(Stack));
    S->top = -1;

    char expression[] =" 48*9+2*5";
    int l = strlen(expression);
    
    //check
    // printf("strlen of expression is %d\n",strlen(expression));
    
    char postfix[30]="";
    int postfixindex=0;
    int j = 1;

    for(int i=0;i<strlen(expression);i++){
            if(expression[i] == ' ' || expression[i] ==',')
                continue;
            
             if(Isoperand(expression[i])){
                
                while(Isoperand(expression[i])){
                    postfix[postfixindex++] = expression[i];
                    i++;
                }
                i--;
                postfix[postfixindex++] = ' ';
                // postfix[postfixindex++] =expression[i];
                // postfix[postfixindex++] = ' ';
                // strncat(postfix,&expression[i],1);
            }
            else if(Isoperator(expression[i])){

                while(!Isempty(S) && !IsOpeningParentheses(expression[i]) && HasHigherPrecedence(S->top,expression[i])){
                    postfix[postfixindex++] = S->arr[S->top];
                    postfix[postfixindex++] = ' ';
                    // strncat(postfix,&S->arr[S->top],1);
                    STACK_POP(S);
                }
                STACK_PUSH(S,expression[i]);
            }
            else if(IsOpeningParentheses(expression[i])){
                STACK_PUSH(S,expression[i]);
            }

            else if(IsclosingParentheses(expression[i])){
                char x = STACK_POP(S);
                while(!(Isempty(S)) && x!= '('  ){
                    postfix[postfixindex++] = x;
                    postfix[postfixindex++] = ' ';

                    x =STACK_POP(S);
                }

                // STACK_POP(S); //to pop opening paranthesis
            }
    }
    while(!Isempty(S)){
        postfix[postfixindex++] = S->arr[S->top];
        postfix[postfixindex++] = ' ';
        STACK_POP(S);
    }

    for(int i=0;i<strlen(postfix);i++){
        printf("%c",postfix[i]);
    }
    
    //check
    // printf("The postfix index is: %d",postfixindex);
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