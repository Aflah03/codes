#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define N 20

typedef struct {
  int number_of_forms;
  int token_number;
} Passenger;

typedef struct {
  int front, rear;
  int arr[N];
} Queue;

int PUSH_TO_QUEUE(Queue *Q, int item) {
  if ((Q->rear + 1) % N == Q->front)
    return -1; // Queue is full
  else if (Q->front == -1) {
    Q->front = 0;
    Q->rear = 0;
  } else {
    Q->rear = (Q->rear + 1) % N;
  }
  Q->arr[Q->rear] = item;
  return 1;
}

int POP_FROM_QUEUE(Queue *Q) {
  int item;
  if (Q->front == -1) {
    return INT_MIN; // Queue is empty
  } else if (Q->front == Q->rear) {
    item = Q->arr[Q->front];
    Q->front = -1;
    Q->rear = -1;
  } else {
    item = Q->arr[Q->front];
    Q->front = (Q->front + 1) % N;
  }
  return item;
}

void PRINT_QUEUE(Queue *Q, Passenger P[], int passenger_count) {
  if (Q->front == -1) {
    printf("Queue is empty.\n");
    return;
  }
  int temp = Q->front;
  while (temp != (Q->rear + 1) % N) {
    int token_number = Q->arr[temp];
    for (int i = 1; i <= passenger_count; i++) {
      if (P[i].token_number == token_number) {
        printf("Token %d, Forms left: %d\n", P[i].token_number,
               P[i].number_of_forms);
      }
    }
    temp = (temp + 1) % N;
  }
  printf("\n");
}

int main() {
  Queue *Q = (Queue *)malloc(sizeof(Queue));
  Passenger P[20];
  int last_token_issued = 0;
  Q->front = -1;
  Q->rear = -1;
  int x;
  int passenger_number = 0;

  printf("CHOOSE!!\n");
  printf("1-GET A TOKEN\n");
  printf("2-SERVE A TICKET\n");
  printf("3-\n");
  printf("4-The current customer being served\n");
  printf("5-Number of customers waiting\n");
  printf(
      "6-List all customers in the queue with the number of forms they have\n");
  printf("7-EXIT\n");
  while (1) {
    printf("------------------------------------------------\n");
    printf("Enter choice: ");
    scanf("%d", &x);
    getchar();

    switch (x) {
    case 1:
      passenger_number++;
      printf("Enter the number of forms: ");
      scanf("%d", &P[passenger_number].number_of_forms);
      last_token_issued++;
      PUSH_TO_QUEUE(Q, last_token_issued);
      P[passenger_number].token_number = last_token_issued;
      printf("Assigned token number %d, no. of forms: %d\n", last_token_issued,
             P[passenger_number].number_of_forms);
      break;

    case 2: {
      if (Q->front == -1) {
        printf("No customers to serve.\n");
        break;
      }

      int current_token = POP_FROM_QUEUE(Q);

      // Find the corresponding passenger in the array
      for (int i = 1; i <= passenger_number; i++) {
        if (P[i].token_number == current_token) {
          printf("Person with token number %d has been served a ticket\n",
                 current_token);
          P[i].number_of_forms--;

          if (P[i].number_of_forms > 0) {
            // Re-add the same token number to the queue
            PUSH_TO_QUEUE(Q, current_token);
            printf("Customer with token number %d re-added to queue, forms "
                   "left: %d\n",
                   current_token, P[i].number_of_forms);
          } else {
            printf("Customer with token number %d has completed all forms.\n",
                   current_token);
          }
          break;
        }
      }
      break;
    }

    case 4:
      if (Q->front != -1) {
        int current_token_number = Q->arr[Q->front];
        for (int i = 1; i <= passenger_number; i++) {
          if (P[i].token_number == current_token_number) {
            printf("Current customer being served: Token %d, Forms left: %d\n",
                   P[i].token_number, P[i].number_of_forms);
            break;
          }
        }
      } else {
        printf("No customers being served right now.\n");
      }
      break;

    case 5:
      if (Q->front != -1) {
        int count = (Q->rear + N - Q->front) % N + 1;
        printf("Number of customers waiting: %d\n", count);
      } else {
        printf("No customers waiting.\n");
      }
      break;

    case 6:
      printf("List of all customers in queue:\n");
      PRINT_QUEUE(Q, P, passenger_number);
      break;

    case 7:
      free(Q);
      return 0;

    default:
      printf("Invalid choice!\n");
      break;
    }
    printf("----------------------------------------------------------\n");
  }
}
