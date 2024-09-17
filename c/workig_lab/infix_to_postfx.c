#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define N 15
typedef struct{
    char arr[N];
    int top;
}Stack;

int StackPush(Stack* S,char item){
    if(S->top == N-1)
        return 0;
    else{
        S->top++;

    }
    S->arr[S->top] = item;
    return 1;
}
char StackPop(Stack *S){
    if(S->top ==-1)
        return -1;
    else{
        char item = S->arr[S->top];
        S->top--;
        return item;
    }
}

bool Isempty(Stack* S){
    if(S->top ==-1) return true;
    return false;
}
void PrintStack(Stack *S ){
    if(S->top ==-1){
        printf("The stack is empyty");
        return;
    }
    else{
    int temp = S->top;
    while(temp != -1){
            printf("%c\n", S->arr[temp]);
            temp--;
    }

    }
   
}
int GetoperatorWight(char C){
    if(C == '+' || C== '-')
        return 1;
    else if(C =='*' || C== '/')
        return 2;
    else if( C == '^')
        return 3;
}
bool IsOpeningParentheses(char C){
    if( C == '(') return true;
    
    return false;
}
bool IsclosingParentheses(char C){
    if( C == ')') return true;
    
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
int main(){
    Stack* S = (Stack*)malloc(sizeof(Stack));
    S->top = -1;

    char expression[] = "a+b*c";

    for(int i=0;i<strlen(expression);i++){
            if(expression[i] = ' ' || expression[i]== ',')
                continue;
            if(IsOpeningParentheses(expression[i])){
                StackPush(S,expression[i]);
            }
            else if(IsclosingParentheses(expression[i])){
                char x = StackPop(S);
                while(x != '('){
                    printf("%c ",x);
                    x = StackPop(S);
                }
                
            }
            else if(Isoperand(expression[i])){
                while(Isoperand(expression[i])){
                    printf("%c",expression[i]);
                    i++;
                }
                i--;
                printf(" ");
            }
            else if(Isoperator(expression[i])){
                if(Isempty(S))
                    StackPush(S,expression[i]);
                else
                {
                char top_stack_item = S->arr[S->top];
                    while(GetoperatorWight(expression[i]) <= GetoperatorWight(top_stack_item)){
                        char x = StackPop(S);
                        printf("%c ",x);
                        top_stack_item = S->arr[S->top];
                    }   
                    StackPush(S,expression[i]);
                }

            }
    }

}