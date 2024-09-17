#include <stdio.h>
#include <stdlib.h>
#define N 5

// Queue definiton
typedef struct {
  int front, rear;
  int arr[N];
  int last_token_issued;
  int current_student;
} Queue;

// push to queue
int QUEUE_PUSH(Queue *Q, int item) {
  if ((Q->rear + 1) % N == Q->front) {
    return -1;
  } else if (Q->front == -1) {
    Q->front = 0;
    Q->rear = 0;

  } else {
    Q->rear = (Q->rear + 1) % N;
  }
  Q->arr[Q->rear] = item;
  return 1;
}
// pop form queue
int QUEUE_POP(Queue *Q) {
  int item;
  if (Q->front == -1)
    return -1;
  else if (Q->front == Q->rear) {
    item = Q->arr[Q->front];
    Q->front = -1;
    Q->rear = -1;
  } else {
    item = Q->arr[Q->front];
    Q->front = (Q->front + 1) % N;
  }
  // printf("the returnd value is: %d item",item);
  return item;
}

// print queue
void Print_Queue(Queue *Q) {
  int temp = Q->front;
  while (temp != (Q->rear) % N) {
    printf("%d\n", Q->arr[temp]);
    temp = (temp + 1) % N;
  }
  if (Q->front != -1)
    printf("%d\n", Q->arr[temp]);
}
int main() {
  Queue *Q = (Queue *)malloc(sizeof(Queue));

  // INITIALIZE VARIBLES
  Q->front = -1;
  Q->rear = -1;
  Q->current_student = -1;
  Q->last_token_issued = 0;

  printf("Choose an option: \n");
  printf("1-Get a token: \n");
  printf("2-Serve a student: \n");
  printf("3-DISPLAY : DISPALY THE CURRENT STUDENTS BEING SERVED\n");
  printf("4-DISPLAY : NO OF STUDENTS WAITING\n");
  printf("5-DISPLAY : LAST TOKEN NUMBER ISSUED\n");
  printf("6-exit\n");
  printf("\nCANTEEN!!\n---------------------\n");
  int x = 0;
  while (x != 6) {
    scanf("%d", &x);
    getchar();
    switch (x) {

    case 1:

      int token_number = ++(Q->last_token_issued);

      if (QUEUE_PUSH(Q, token_number) == -1) {

        printf("queue is full , cannot assign a token right now.\n");
      } else {
        printf("Issued a token, number: %d\n", token_number);
      }
      printf("\nThe queue is : \n");
      Print_Queue(Q);

      break;

    case 2:
      if (Q->front == -1) {
        printf("QUEUE is empty.");
      } else {
        Q->current_student = QUEUE_POP(Q);
        printf("serving student with token number %d.\n", Q->current_student);
      }
      printf("\nThe queue is : \n");
      Print_Queue(Q);

      break;

    case 3:
      if (Q->current_student == -1)
        printf("No one is being sereved now");
      else {
        printf("Student with token number %d is now being served\n",
               Q->current_student);
        printf("\nThe queue is : \n");
        Print_Queue(Q);
      }
      break;

    case 4:
      int temp = Q->front;
      int count = 0;
      while (temp !=
             ((Q->rear)) % N) { // temp != (Q->rear)+!%N  wont work when array
                                // is full as temp = Q->fornt in the begining
        // temp  = Q->rear+1 % N , when queue is full , so print no fo student
        // waiting=0 , in full conditin . NOw the code is fixed
        count++;
        temp = (temp + 1) % N;
      }
      if (Q->front != -1)
        count++;
      printf("NO. of studentns waitng: %d\n", count);
      printf("\nThe queue is : \n");
      Print_Queue(Q);

      break;

    case 5:
      printf("The last token number issued is: %d\n", Q->last_token_issued);
      printf("\nThe queue is : \n");
      Print_Queue(Q);

      break;

    default:
      break;
    }

    printf("\n----------------------------------\n");
  }
}
