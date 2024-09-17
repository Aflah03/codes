#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct list {
  int coeff; // coefficienet
  int exp;   // exponent
  struct list *next;

} Node;

Node *getNode() {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {
    printf("Error allocating memory");
  }
  newNode->next = NULL;

  newNode->coeff = 0;
  newNode->exp = 0;
  return newNode;
}

void PRINT_LIST(Node *head) {
  Node *temp = head->next;
  int count = 0;
  while (temp != NULL) {
    if (count != 0)
      printf(" + ");
    count++;
    printf("%dx^%d", temp->coeff, temp->exp);
    temp = temp->next;
  }
}
Node *INSERT_POLYNOMIAL() {
  Node *head_of_polynomial = getNode();

  Node *temp = head_of_polynomial;
  int n;
  printf("enter no of terms in the polynomial: \n");
  scanf("%d", &n);
  int count = 0;

  for (int i = 0; i < n; i++) {
    Node *newNode = getNode();
    temp->next = newNode;
    temp = newNode;
    printf("enter power of coeff and power of term %d: ", count++);

    scanf("%d %d", &newNode->coeff, &newNode->exp);
  }
  return head_of_polynomial;
}
Node *Add_Univariate(Node *polynomial_1, Node *polynomial_2) {
  Node *head = getNode();
  Node *apos = polynomial_1;
  Node *bpos = polynomial_2;
  Node *temp = head;

  while (apos != NULL && bpos != NULL) {
    if (apos->exp == bpos->exp) {
      temp->next = getNode();
      temp = temp->next;
      temp->coeff = apos->coeff + bpos->coeff;
      temp->exp = apos->exp;
      apos = apos->next;
      bpos = bpos->next;
    } else if (apos->exp > bpos->exp) {
      temp->next = getNode();
      temp = temp->next;
      temp->coeff = apos->coeff;
      temp->exp = apos->exp;
      apos = apos->next;
    } else if (bpos->exp > apos->exp) {
      temp->next = getNode();
      temp = temp->next;
      temp->coeff = bpos->coeff;
      temp->exp = bpos->exp;
      bpos = bpos->next;
    }
  }
  while (apos != NULL) {
    temp->next = getNode();
    temp = temp->next;
    temp->coeff = apos->coeff;
    temp->exp = apos->exp;
    apos = apos->next;
  }
  while (bpos != NULL) {
    temp->next = getNode();
    temp = temp->next;
    temp->coeff = bpos->coeff;
    temp->exp = bpos->exp;
    bpos = bpos->next;
  }
  return head;
}
int main() {
  Node *polynomial_1;
  Node *polynomial_2;
  Node *result;

  printf("Polynomial 1\n");
  polynomial_1 = INSERT_POLYNOMIAL();
  printf("polynomial 2\n");
  polynomial_2 = INSERT_POLYNOMIAL();

  printf("Polynomial 1: \n");
  PRINT_LIST(polynomial_1);
  printf("\nPolynomial 2: \n");
  PRINT_LIST(polynomial_2);

  printf("\n Adding polynomial 1 and 2: \n");
  result = Add_Univariate(polynomial_1, polynomial_2);
  PRINT_LIST(result->next);
}
