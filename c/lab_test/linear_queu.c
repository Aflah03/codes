#include<stdio.h>
#include<stdlib.h>


typedef struct{
    int front,rear;
    int arr[20];
}Queue;

int Queue_push(Queue *Q,int item){
    if(Q->front ==4)
        return -1;
    else if(Q->front==-1){
        (Q->front) =0;
        (Q->rear) =0;
        (Q->arr[Q->rear]) = item;
        
    }
    else{
        (Q->rear)++;

        Q->arr[Q->rear] = item;
    }
}
int QueuePop(Queue *Q){
    int item;
    if(Q->front ==-1)
        return -1;
    else if (Q->front == Q->rear){
        item = Q->arr[Q->front];
        Q->front  =0;
        Q->rear =0;

    }
    else{
        item = Q->arr[Q->front];
        Q->front ++;
    }
    return item;
}
void Print_Stack(Queue *Q){
    int temp = Q->front;
    while(temp !=4){
        printf("%d ",Q->arr[temp]);
         temp++;

    }
}

int main(){

    Queue* Q = (Queue*)malloc(sizeof(Queue));
    Q->front  = -1;
    Q->rear = -1;
    /************************************************* * 
    * 
    * 
    *                                                  *
    *                                                  *
    *                                                  *
    *                                                  *
    *        NOT INITIALISING QUEUE->fRONT     
    *                                                  *
    *        AND q->REAR TO -1 WAS THE BIG PROBELM     *
    *                                                  *
    *                                                  *
    *                                                  *
    *                                                  *
    *                                                  *
    *                                                  *
    ****************************************************/ 

    // Q->arr[Q->front] =11;

    // printf("%d ",Q->arr[Q->front]);
    Queue_push(Q,23);
    Queue_push(Q,11);
    Queue_push(Q,121);
    Queue_push(Q,45);

     int x = QueuePop(Q);
        printf("POPPPED ELEMENT: %d\n",x);
    x = QueuePop(Q);
        printf("POPPPED ELEMENT: %d\n",x);

    x = QueuePop(Q);
        printf("POPPPED ELEMENT: %d\n",x);



   // Print_Stack(Q);
}