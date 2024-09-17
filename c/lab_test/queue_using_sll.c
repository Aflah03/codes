#include <stdio.h>
#include <stdlib.h>

typedef struct list {
  int data;
  struct list *next;
} Node;
Node *getNode() {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->next = NULL;
  newNode->data = 0;
  return newNode;
}
Node *head = NULL;

Node *front = NULL;
Node *rear = NULL;
int ENQUEUE(int item) {
  // no need for overflow condition
  if (front == NULL) {
    front = head->next;
    rear = head->next;
  } else {
    rear = rear->next;
  }
  rear->data = item;
  return 1;
}
int DEQUEUE() {
  int item;
  if (front == NULL)
    return -1; // underflow
  else if (front == rear) {
    item = front->data;
    Node* temp = front;
    :
    head->next= NULL;
    front = NULL;
    rear = NULL;
  } else {
    item = front->data;
    Node *temp = front;
    if (front->next != NULL)
      head->next = front->next;
    front = head->next;
  }
  return 1;
}
int main() { head = getNode(); }
