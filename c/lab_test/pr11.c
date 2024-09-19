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
    temp = temp->next; // temp->next is same as newNode
    printf("enter power of coeff and power of term %d: ", count++);

    scanf("%d %d", &newNode->coeff, &newNode->exp);
    getchar();
  }
  return head_of_polynomial;
}
Node *Add_Univariate(Node *polynomial_1, Node *polynomial_2) {
  Node *head = getNode();
  Node *apos = polynomial_1->next;
  Node *bpos = polynomial_2->next;
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
Node *MULTIPLY_WITHOUT_ADDING_ALL(Node *polynomial_1, Node *polynomial_2) {
  Node *result = getNode();

  Node *temp = result;
  Node *temp1 = polynomial_1->next;
  Node *temp2 = polynomial_2->next;
  Node* astart = temp1;
  Node* bastart = temp2;
  while (temp1 != NULL) {
    temp2 = bastart;
    printf("currently running %dx^%d\n",temp1->coeff,temp1->exp);
    while (temp2 != NULL) {
      temp->next = getNode();
      temp = temp->next;
      temp->exp = temp1->exp + temp2->exp;
      temp->coeff = (temp1->coeff) * (temp2->coeff);
      temp2 = temp2->next;
    }
    temp1 = temp1->next;
  }
  return result;
}
Node* RESOLVE_MULTIPLICATOIN_ADDITOIN(Node* polynomial){
  Node* result = getNode();
  int countpowers=0;
  int powers[100];
  Node* temp = result;
  Node* temp1 = polynomial->next;
  while(temp1!= NULL){
    powers[countpowers++]= temp1->exp;
    temp1 = temp1->next;
  }
  printf("the value of count powers is %d",countpowers);
  for(int i=0;i<countpowers;i++){
    for(int j=0;j<countpowers-i-1;j++){
      if(powers[j]< powers[j+1]){
        int temp = powers[j+1];
        powers[j+1] = powers[j];
        powers[j] = temp;
      }

    }
  }

  for(int i=0;i<countpowers;i++){
    for(int j=0;j<countpowers-1;j++){
      if(powers[j]==powers[j+1]){
        for(int k=j;k<=countpowers-1;k++){
            powers[k] =powers[k+1];
        }
        countpowers--;
      }
    }
  }
  printf("the value of count powesrs after emoveing duplicate is : %d\n",countpowers);
  temp = result;
   temp1 = polynomial->next;
  int times = 0;
  while(times!=countpowers){
   temp->next = getNode();
    temp = temp->next;
    temp->coeff =0;
    temp->exp = powers[times];
    temp1 = polynomial->next;
    while(temp1 != NULL){
      if(temp1->exp == temp->exp){
          temp->coeff += temp1->coeff;
      }
      temp1 = temp1->next;
    }
    times++;
  }
  return result;
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

  printf("Choose operation\n");
  printf("1- Addition:\n");
  printf("2- Multiplication:\n");
  int operation;
  scanf("%d", &operation);
  getchar();
  switch (operation) {
  case 1:
    printf("\n Adding polynomial 1 and 2: \n");
    result = Add_Univariate(polynomial_1, polynomial_2);
    PRINT_LIST(result);
    break;
  case 2:
      printf("Multitplying polynomials: \n");
      result = MULTIPLY_WITHOUT_ADDING_ALL(polynomial_1,polynomial_2);
      // Node* resolved = RESOLVE_MULTIPLICATOIN_ADDITOIN(result);
      result = RESOLVE_MULTIPLICATOIN_ADDITOIN(result);
        PRINT_LIST(result);
      // PRINT_LIST(resolved);
    break;
  case 3:
    return 0;
  }
}
