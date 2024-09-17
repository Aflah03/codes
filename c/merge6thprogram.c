#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 15
// the infix to postfix in this have some  ligical errors , use narasimhan sirs Pusedocode instead
/********************************************************************************************************************************
* *
* *
* *
* *
*      how to make this code
    Infix to Postfix Conversion
    Initialize a stack of characters to hold the operators (^, *, /, +, -)
    • Parse the infix string left to right:
    If an operand is read:
    • Then output it into the postfix expression expression
    Else if ‘(‘ is read
    • Then push it into the stack
    • Else if E ‘)’ is read:
    • Then pop and output into the postfix expression until matching ‘(‘ is
popped from the stack • Else if an operator Xis read: • If the stack is empty or
character Y(top of the stack) = ‘(‘ or Yis an operator of lower precedence than
X, then push X • While Y is an operator of higher or equal precedence than X,
pop and output Y • Then push X • When we reach the end of input, pop and output
until stack is empty *
* *
* *
*********************************************************************************************************************************/

// stack
typedef struct {
  char arr[N];
  int top;
} Stack;

int STACK_PUSH(Stack *S, char item) {
  if (S->top == N - 1) //  (*S).top
    return -1;
  else {
    S->top++;
    S->arr[S->top] = item;
    return 1;
  }
}
char STACK_POP(Stack *S) {
  if (S->top == -1) {
    return 0;
  } else {
    char item = S->arr[S->top];
    S->top--;
    return 1;
  }
}
bool Isempty(Stack *S) {
  if (S->top == -1)
    return true;

  return false;
}

// seocnd stack
typedef struct {
  int arr[N];
  int top;
} Stack1;

int STACK_PUSH1(Stack1 *S, int item) {
  if (S->top == N - 1)
    return -1;
  else {
    S->top++;
    S->arr[S->top] = item;
    return 1;
  }
}
int STACK_POP1(Stack1 *S) {
  if (S->top == -1) {
    return 0;
  } else {
    int item = S->arr[S->top];
    S->top--;
    return item;
  }
}

bool IsclosingParentheses(char C);
bool IsOpeningParentheses(char C);
// function to verify whether an operator has higher precedence or not.
int HasHigherPrecedence(char operator1, char operator2);

// Function to verify whether a character is operator symbol or not.
bool Isoperator(char C);

// Function to verify whether a character is alphanumeric character or
// not(letter or digit) or not.
bool Isoperand(char C);

// MAIN
int main() {
  Stack *S = (Stack *)malloc(sizeof(Stack));
  S->top = -1;
  Stack1 *S1 = (Stack1 *)malloc(sizeof(Stack1));
  S1->top = -1;

  int choice;
  while (1) {
    printf("\n-------------------------------------------------------\n");
    printf("1.Convert infix to postfix: \n");
    printf("2.Evaluate postfix: \n");
    printf("3.EXIT\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();//
    /*
     * If you use scanf() before fgets(), you might run into issues where the newline character (\n)
     * left in the input buffer by scanf() causes fgets() to read an empty line. You can flush the input buffer 
     * by adding getchar() after scanf():*/

    switch (choice) {
    case 1:
      //char expression[] = " 48*9+2*5";
        char* expression = (char*)malloc(100);
      printf("Enter the infix Expression: ");
      gets(expression);
      int l = strlen(expression);
      
      // check
      //  printf("strlen of expression is %d\n",strlen(expression));

      char postfix[30] = "";
      int postfixindex = 0;
      int j = 1;

      for (int i = 0; i < strlen(expression); i++) {
        if (expression[i] == ' ' || expression[i] == ',')
          continue;

        if (Isoperand(expression[i])) {

          while (Isoperand(expression[i])) {
            postfix[postfixindex++] = expression[i];
            i++;
          }
          i--;
          postfix[postfixindex++] = ' ';
          // postfix[postfixindex++] =expression[i];
          // postfix[postfixindex++] = ' ';
          // strncat(postfix,&expression[i],1);
        } else if (Isoperator(expression[i])) {

          while (!Isempty(S) && !IsOpeningParentheses(expression[i]) &&
                 HasHigherPrecedence(S->top, expression[i])) {
            postfix[postfixindex++] = S->arr[S->top];
            postfix[postfixindex++] = ' ';
            // strncat(postfix,&S->arr[S->top],1);
            STACK_POP(S);
          }
          STACK_PUSH(S, expression[i]);
        } else if (IsOpeningParentheses(expression[i])) {
          STACK_PUSH(S, expression[i]);
        }

        else if (IsclosingParentheses(expression[i])) {
          char x = STACK_POP(S);
          while (!(Isempty(S)) && x != '(') {
            postfix[postfixindex++] = x;
            postfix[postfixindex++] = ' ';

            x = STACK_POP(S);
          }

         //  STACK_POP(S); //to pop opening paranthesis
        }
      }
      while (!Isempty(S)) {
        postfix[postfixindex++] = S->arr[S->top];
        postfix[postfixindex++] = ' ';
        STACK_POP(S);
      }

        printf("POSTFIX EXPRESSION: ");
      for (int i = 0; i < strlen(postfix); i++) {
        if(postfix[i] != '(' && postfix[i] != ')')
          printf("%c", postfix[i]);
      }
      break;
    case 2:
      char *postfixExp = (char *)malloc(100);
      // scanf("%s",postfixExp);

      gets(postfixExp);
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
          STACK_PUSH1(S1, operand_value);
        }

        else if (Isoperator(postfixExp[i])) {
          int y = STACK_POP1(S1);
          int x = STACK_POP1(S1);
          char op = postfixExp[i];
          // printf("The value of x is : %c\n",x);
          // printf("The value of y is : %c\n",y);
          switch (op) {
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
          STACK_PUSH1(S1, value);
        }
      }
      int result = STACK_POP1(S1);
      printf("The reuslt is %d\n", result);

      break;
    case 3:
      return 0;
    } // switch

  } // while loop

  // check
  //  printf("The postfix index is: %d",postfixindex);
}

bool Isoperand(char C) {
  if (C >= '0' && C <= '9')
    return true;
  if (C >= 'a' && C <= 'z')
    return true;
  if (C >= 'A' && C <= 'Z')
    return true;
  return false;
}

bool Isoperator(char C) {
  if (C == '+' || C == '-' || C == '*' || C == '/' || '^')
    return true;
  return false;
}

// Function to verify whether an operator is right associative or not.
int IsRightAssociative(char op) {
  if (op == '^')
    return true;
  return false;
}
bool IsOpeningParentheses(char C) {
  if (C == '(')
    return true;

  return false;
}
bool IsclosingParentheses(char C) {
  if (C == ')')
    return true;

  return false;
}
int GetOperatorWeight(char op) {
  int weight = -1;
  switch (op) {
  case '+':
  case '-':
    weight = 1;
    break;
  case '*':
  case '/':
    weight = 2;
  case '^':
    weight = 3;
    break;
  }
  return weight;
}
int HasHigherPrecedence(char operator1, char operator2) {

  int op1Weight = GetOperatorWeight(operator1);
  int op2Weight = GetOperatorWeight(operator2);

  // If operators have equal precedence, return true if they are left
  // associative. return false, if right associative. if operator is
  // left-associative, left one should be given priority.

  if (op1Weight == op2Weight) {

    if (IsRightAssociative(operator1))
      return false;
    else
      return true;
  }
  return op1Weight > op2Weight ? true : false;
}

// 2nd part

// stack
