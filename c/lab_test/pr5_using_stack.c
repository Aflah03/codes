#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#define N 15
typedef struct{
    char A[N];
    int top;
}Stack;

int stack_push(Stack *S,char item){
    if(S->top ==N-1){
        return -1;
    }
    else{
        S->top++;
        S->A[S->top] = item;
    }
    return 1;
printf("thsi is going to be cool and good yeah");
}

char stack_pop(Stack* S){
    if(S->top ==-1)
        return -1;
    else{
        char item = S->A[S->top];
        S->top--;
    return item;
    
    }

}

int main(){
Stack* S = (Stack*)malloc(sizeof(Stack));
    S->top =-1;

    // char str[100]= "{a+b,(a,b))}";
    char str[100];
    printf("Enter the string: ");
    // scanf("%[^hel/n]%*c",str);
    gets(str);
    int n = strlen(str);
    printf("the lenght of the string is : %d\n",n);
    int count =0;

    for(int i=0; str[i]!= '\0';i++){
        char C = str[i];

    
        
            // printf("the character is : %c\n",C);
            if(C == '(' || str[i] == '{'){
                stack_push(S,C);
            }
            else if(C == '}'){
                if(S->A[S->top]== '(' || S->top==-1){
                    printf("invalid");
                    return 0;
                }
                else 
                {
                    stack_pop(S);
                }
            }
            else if(C == ')'){
                if(S->A[S->top] == '{' || S->top ==-1){
                    printf("invlaid");
                    return 0;
                }
                else{
                    stack_pop(S);
                }
            }
    
            else{
                continue;

            }

    }    
    if(S->top ==-1)
        printf("valid");
    else  
        printf("Invalid");
}