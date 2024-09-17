#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 25
typedef struct {
  char *A[N];
  int front, rear;
} Deque;

int INSERT_FRONT_DEQUE(Deque *Q, char *item) {
  if ((Q->rear + 1) % N == Q->front)
    return -1;
  else if (Q->front == -1) {
    Q->front = 0;
    Q->rear = 0;
  } else {
    Q->front = (Q->front + N - 1) % N;
  }
  Q->A[Q->front] = strdup(item); // copies item to char* A[Q->front] // strdup
                                 // return pointer to allocated memory
  return 1;
}
char *DELETE_REAR_ITEM(Deque *Q) {
  char *item;
  if (Q->front == -1)
    return NULL;
  else if (Q->front == Q->rear) {
    item = Q->A[Q->rear];
    Q->front = -1;
    Q->rear = -1;
  }
  else {
    item = Q->A[Q->rear];
    Q->rear = (Q->rear + N - 1) % N;
  }
  return item;
}
int INSERT_REAR_DEQUE(Deque *Q, char *item) {
  if ((Q->rear + 1) % N == Q->front) {
    return -1;
  } else if (Q->front == -1) {
    Q->front = 0;
    Q->rear = 0;

  } else {
    Q->rear = (Q->rear + 1) % N;
  }
  Q->A[Q->rear] = strdup(item);
  return 1;
}

char *DELEETE_FRONT_DEQUE(Deque *Q) {
  char *item;
  if (Q->front == -1)
    return NULL;
  else if (Q->front == Q->rear) {
    item = Q->A[Q->front];
    Q->front = -1;
    Q->rear = -1;
  } else {
    item = Q->A[Q->front];
    Q->front = (Q->front + 1) % N;
  }
  // printf("the returnd value is: %d item",item);
  return item;
}

void Print_Queue(Deque *Q) {
  int temp = Q->front;
  while (temp != (Q->rear) % N) {
    printf("%s\n", Q->A[temp]);
    temp = (temp + 1) % N;
  }
  if (Q->front != -1)
    printf("%s", Q->A[temp]);
}

// insert front and delete at rear newly written
// insert rear and delete form fornt is copied form labtoken7
int main() {
  Deque *Q = (Deque *)malloc(sizeof(Deque));
  Q->front = -1;
  Q->rear = -1;
  char name[N];
  char *returnName;
  int choice;
    printf("\n1. Add Student to left(latecomer)\n");
    printf("2. Add Student to right(latecomer)\n");
    printf("3. Call student from left\n");
    printf("4. Call student from right\n");
    printf("5. Name of students on the bench starting from left to right\n");
    printf("6. EXIT\n");
  while (1) {
    // consder left side of becch to be the front of Deque
    printf("\n-----------------------------------------------------------\n");
    printf("Enter your choice:");
    scanf("%d", &choice);
    getchar();
    printf("-----------------------------------------------------------\n");
    switch (choice) {
    case 1:
      printf("Enter students Name: ");
      // scanf("%s", name);
      fgets(name, N, stdin);
      name[strcspn(name, "\n")] = '\0';  // Remove the newline character
      INSERT_FRONT_DEQUE(Q, strdup(name));
      printf("%s Added to left of bench", name);
      break;
    case 2:
      printf("Enter students Name: ");
      fgets(name, N, stdin);
      name[strcspn(name, "\n")] = '\0';  // Remove the newline character
      // scanf("%s", name);
      INSERT_REAR_DEQUE(Q, name);
      printf("%s Added to right of bench", name);
      break;
    case 3:
      returnName = DELEETE_FRONT_DEQUE(Q);
      if (returnName == NULL) {
        printf("Bench is empty");
      } else {
        printf("%s has been called from left side of the bench\n", returnName);
      }
      break;
    case 4:
      returnName = DELETE_REAR_ITEM(Q);
      if (returnName == NULL) {
        printf("Bench is empty");
      } else {
        printf("%s has been called from right side of the bench\n", returnName);
      }
      break;
    case 5:
      printf("Students on first bench from left to right is : \n\n");
      Print_Queue(Q);
      break;

    case 6:
      return 0;
    }
  }
}
