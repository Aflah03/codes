#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct List {
  int data;
  struct List *next;
} Node;

// implement stack and queue using linked lists
/*
  stack =>    push-     insert at end
 *            pop -     remove from the end

  Queue =>   enqueue-  insert at the end
 *            dequeue-  remove from the beginging
 */

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

// REMOVE FROM END
int SLL_REMOVE_FROM_END(Node *head) {
  int item = 0;
  Node *p = head->next;
  Node *q = head;
  while (p != NULL && p->next != NULL) {
    q = p;
    p = p->next;
  }
  if (p == NULL) {
    printf("The list is empty");
    return -1;
  }
  q->next = NULL;
  item = p->data;
  free(p);
  return item;
}

// REMOVE FROM FRONT
int SLL_REMOVE_FROM_FRONT(Node *head) {
  int item;
  Node *temp = head->next;
  if (temp == NULL) {
    printf("The list is empty");
    return -1;
  }
  item = temp->data;
  head->next = temp->next;
  free(temp);
  return item;
}

void SLL_PRINT_LIST(Node *head) {
  Node *temp = head->next;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
}
int main() {
  int item;
  int operation;
  Node *Shead = NULL;
  Node *Qhead = NULL;
  Shead = getNode();
  Qhead = getNode();

  printf("1- STACK\n");
  printf("2- QUEUE\n");
  printf("3 - EXIT\n");
  printf("choose: ");
  while (true) {
    int choice = 0;
    scanf("%d", &choice);
    getchar();

    switch (choice) {
    case 1:
      /*stack =>    push-     insert at end
     *            pop -     remove from the end

      Queue =>   enqueue-  insert at the end
     *            dequeue-  remove from the beginging
     */
      while (true) {
        int flag = 0;
        printf("1-Push: \n");
        printf("2-Pop: \n");
        printf("3- Print Stack\n");
        printf("4- EXIT\n");
        printf("option: ");
        scanf("%d", &operation);
        getchar();
        switch (operation) {
        case 1:
          printf("Enter number to push\n");
          scanf("%d", &item);
          getchar();
          SLL_INSERT_AT_END(Shead, item);
          break;
        case 2:
          item = SLL_REMOVE_FROM_END(Shead);
          if (item == -1) {
            printf("List is empty\n");

          } else {
            printf("Popped %d\n", item);
          }
          break;
        case 3:
          printf("The Stack is: \n");
          SLL_PRINT_LIST(Shead);
          printf("\n");
          break;
        case 4:
          return 0;
        }
      }

      break;

    case 2:
      // Queue
      //

      while (true) {
        int flag = 0;
        printf("1-ENQUEUE: \n");
        printf("2-DEQUEUE: \n");
        printf("3- Print QUEUE \n");
        printf("4- EXIT\n");
        printf("option: ");
        scanf("%d", &operation);
        getchar();
        switch (operation) {
        case 1:
          printf("Enter number to enqueue\n");
          scanf("%d", &item);
          getchar();
          SLL_INSERT_AT_END(Qhead, item);
          break;
        case 2:
          item = SLL_REMOVE_FROM_FRONT(Qhead);
          if (item == -1) {
            printf("QUEUE is empty\n");

          } else {
            printf("dequeued %d\n", item);
          }
          break;
        case 3:
          printf("The queue is: \n");
          SLL_PRINT_LIST(Qhead);
          printf("\n");
          break;
        case 4:
          return 0;
        }
          
      }
      break;
    case 3:
      return 0;
    }
  }
}
