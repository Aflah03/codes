#include<stdio.h>
#include<limits.h>
#define N 15
// COMPLETE 

typedef struct{
    int A[N];;
    int top;
}Stack;

int i=0;
int* p =&i;
// int n=15;

int STACK_PUSH(Stack* S,int item){
    if(S->top == N-1){
        return -1;
    }
    else{
        S->top++;
        printf("AT push %d: %d\n",(*p)+1,S->top);
        (*p)++;
        S->A[S->top] =item;
        return 1;
    }

}
int STACK_POP(Stack* S){
    if(S->top == -1){
        return INT_MIN;
    }
    else{
        int item = S->A[S->top];
        S->top--;
        return item;
    }
}
void Print_Stack(Stack *S){
    int i=0;
    printf("The stack is: ");
    while((i-1)!= S->top){
        printf("%d ",(*S).A[i]); 
        i++;

    }
}

int main(){
    Stack* S = (Stack*)malloc(sizeof(Stack));
    S->top =-1;
    //if it wasnt typedef
    // struct Stack* S = (struct Stack*)malloc(sizeof(struct Stack))
    
    STACK_PUSH(S,45);
    STACK_PUSH(S,23);
    STACK_PUSH(S,11);
    STACK_PUSH(S,25);
    STACK_PUSH(S,43);
    STACK_PUSH(S,35);

    // int x = STACK_POP(S);
    // printf("%d",x);

    // printf("%d",S->A[1]);
    Print_Stack(S);
}


  
   
    








