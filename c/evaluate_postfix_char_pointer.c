#include <math.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 15

// stack
typedef struct {
  int arr[N];
  int top;
} Stack;

int STACK_PUSH(Stack *S, int item) {
  if (S->top == N - 1)
    return -1;
  else {
    S->top++;
    S->arr[S->top] = item;
    return 1;
  }
}
int STACK_POP(Stack *S) {
  if (S->top == -1) {
    return 0;
  } else {
    int item = S->arr[S->top];
    S->top--;
    return item;
  }
}

bool Isoperand(char C) {
  if (C >= '0' && C <= '9')
    return true;
  // if(C >='a' && C<='z') return true;
  // if(C >='A' && C<='Z') return true;
  return false;
}

bool Isoperator(char C) {
  if (C == '+' || C == '-' || C == '*' || C == '/' || '^')
    return true;
  return false;
}

int main() {
  Stack *S = (Stack *)malloc(sizeof(Stack));
  S->top = -1;
  // char postfixExp[20] = "23 50 5 / +";

  char *postfixExp = (char *)malloc(100);
  // scanf("%s",postfixExp);
  
  fgets(postfixExp, 100, stdin);
  postfixExp[strcspn(postfixExp, "\n")] = '\0';
  // gets(postfixExp);
  printf("the post fix expression is : %s\n", postfixExp);
  int value = 0;
  int times = 1;
  for (int i = 0; i < strlen(postfixExp); i++) {
    if (postfixExp[i] == ' ' || postfixExp[i] == ',')
      continue;

    if (Isoperand(postfixExp[i])) {
      int operand_value = 0; // converet ascii value to actual int
      while (Isoperand(postfixExp[i])) {
        operand_value = operand_value * 10 + postfixExp[i] - '0';
        i++;
      }
      i--;
      // printf("the stuff %d is operand\n", postfixExp[i]);
      // printf("Now we are at  operand for the %d time\n", times++);
      STACK_PUSH(S, operand_value);
    }

    else if (Isoperator(postfixExp[i])) {
      int y = STACK_POP(S);
      int x = STACK_POP(S);
      char op = postfixExp[i];
      // printf("The value of x is : %c\n",x);
      // printf("The value of y is : %c\n",y);
      switch (op) {
      case '^':
        value = pow(x, y);
        break;
      case '+':
        value = x + y;
        break;
      case '-':
        value = x - y;
        break;
      case '/':
        value = x / y;
        break;
      case '*':
        value = x * y;
        break;
      }
      STACK_PUSH(S, value);
    }
  }
  int result = STACK_POP(S);
  printf("The reuslt is %d\n", result);
}
