#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct List {
  int data;
  struct List *next;
} Node;

Node *getNode() {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {

    printf("Error in allocating memory");
    return NULL;
  }
  newNode->next = NULL;
  newNode->data = 0;
  return newNode;
}

// INSERT TO END
int SLL_INSERT_AT_END(Node *head, int item) {
  Node *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  Node *newNode = getNode();
  newNode->data = item;
  temp->next = newNode;
  return 1;
}

void SLL_PRINT_LIST_IN_REVERSE_ORDER_USING_RECURSION(Node *temp) {
  if (temp == NULL)
    return;
  SLL_PRINT_LIST_IN_REVERSE_ORDER_USING_RECURSION(temp->next);
  printf("%d ", temp->data);
}
void SLL_PRINT_LIST(Node *head) {
  Node *temp = head->next;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
}
Node *CONVERT_TO_SLL(char arr[]) {
  Node *number1 = getNode();
  Node *temp = number1;
  char *item = arr;
  while (*item != '\0') {
    if (*(item) == ' ') {
      item++;
    } else {
      int value = *item - '0';
      printf("the value is %d\n", value);
      temp->next = getNode();
      temp = temp->next;
      temp->data = value;
      item++;
    }
  }
  return number1;
}

Node *CONVERT_TO_SLL_IN_REVERSE(char arr[]) {
  Node *number1 = getNode();
  Node *temp = number1;
  char *item = arr;
  int n = 0;
  while(*item != '\0'){
    item++;
    n++;
  }
  item = arr;
  printf("n is : %d",n);
  for(int i=n-1;i>=0;i--){
    printf("the value of i in loop is %d",i);
    
  
    if (*(item+i) == ' ') {
      continue;
    } else {
      int value = *(item+i) - '0';
      printf("the value is %d\n", value);
      temp->next = getNode();
      temp = temp->next;
      temp->data = value;
    }
  }
  return number1;
}
Node* SLL_ADD_TWO_SLL(Node* list1,Node* list2){
 Node* HEAD_OF_FINAL_RESULT = getNode();

  int carry;
  int reminder;
  int added_result;

  Node* temp1 = list1->next;
  Node* temp2 = list2->next;
  Node* temp = HEAD_OF_FINAL_RESULT;
  while(temp1!= NULL && temp2!= NULL){
    temp->next = getNode();
    temp = temp->next;



  } 
  return HEAD_OF_FINAL_RESULT;
}

int main() {
  Node *head = getNode();
  // TEST*************
  // SLL_INSERT_AT_END(head,2);
  // SLL_INSERT_AT_END(head,3);
  // SLL_INSERT_AT_END(head,4);
  // SLL_INSERT_AT_END(head,5);
  //
  //
  //
  // printf("\n");
  // SLL_PRINT_LIST_IN_REVERSE_ORDER_USING_RECURSION(head->next);

  char arr[100];
  printf("Enter the first Number:\n");
  fgets(arr, 100, stdin);
  arr[strcspn(arr, "\n")] = '\0';
  Node* number1 = CONVERT_TO_SLL_IN_REVERSE(arr);

  printf("Enter the Second Number:\n");
  fgets(arr, 100, stdin);
  arr[strcspn(arr, "\n")] = '\0';
  Node *number2 = CONVERT_TO_SLL_IN_REVERSE(arr);

  Node* result = SLL_ADD_TWO_SLL(number1,number2);//adding from right of number to left thats
  //why we reverse the list

  // SLL_PRINT_LIST(number1);
  // SLL_PRINT_LIST(number2);
}
