#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 15
typedef struct {
  char A[N];
  int top;
} Stack;

int stack_push(Stack *S, char item) {
  if (S->top == N - 1) {
    return -1;
  } else {
    S->top++;
    S->A[S->top] = item;
  }
  return 1;
}

char stack_pop(Stack *S) {
  if (S->top == -1)
    return -1;
  else {
    char item = S->A[S->top];
    S->top--;
    return item;
  }
}

int main() {
  Stack *S = (Stack *)malloc(sizeof(Stack));
  S->top = -1;

  char str[100];
  printf("Enter the string: ");
  fgets(str, 100, stdin);
  int n = strlen(str);
  int count = 0;

  for (int i = 0; str[i] != '\0'; i++) {
    char C = str[i];

    if (C == '(' || str[i] == '{') {
      stack_push(S, C);
    } else if (C == '}') {
      if (S->A[S->top] == '(' || S->top == -1) {
        printf("Invalid\n");
        return 0;
      } else {
        stack_pop(S);
      }
    } else if (C == ')') {
      if (S->A[S->top] == '{' || S->top == -1) {
        printf("Invlaid\n");
        return 0;
      } else {
        stack_pop(S);
      }
    }

    else {
      continue;
    }
  }
  if (S->top == -1)
    printf("Valid\n");
  else
    printf("Invalid\n");
}
