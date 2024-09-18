
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
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

void SLL_PRINT_LIST_IN_REVERSE_ORDER_USING_RECURSION(Node* temp){
    if(temp==NULL)
      return;
    SLL_PRINT_LIST_IN_REVERSE_ORDER_USING_RECURSION(temp->next);
    printf("%d ",temp->data);
}
void SLL_PRINT_LIST(Node *head) {
  Node *temp = head->next;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
}
int main(){
  // printf("Enter the number of Nodes");
  // int n;
  // scanf("%d",&n);
  // getchar();
  Node* head = getNode();
  SLL_INSERT_AT_END(head,2);
  SLL_INSERT_AT_END(head,3);
  SLL_INSERT_AT_END(head,4);
  SLL_INSERT_AT_END(head,5);
  

  SLL_PRINT_LIST(head);
  
  printf("\n");
  SLL_PRINT_LIST_IN_REVERSE_ORDER_USING_RECURSION(head->next);

}
