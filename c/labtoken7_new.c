#include<stdio.h>
#include<stdlib.h>
#define N 20

//Queue definiton
typedef struct{
    int front,rear;
    int arr[N];
    int last_token_issued;
    int current_student;
}Queue;

//push to queue
int QUEUE_PUSH(Queue* Q,int item){
    if((Q->rear+1)%N ==Q->front){
        return -1;
    }
    else if(Q->front ==-1){
        Q->front =0;
        Q->rear =0;

    }
    else{
        Q->rear = (Q->rear+1)%20;

    }
    (*Q).arr[Q->rear] = item;
}


//pop form queue
int QUEUE_POP(Queue* Q){
    int item;
    if(Q->front == -1)
    return -1;
    else if(Q->front == Q->rear){
        item = Q->arr[Q->front];
        Q->front =-1;
        Q->rear =-1;
    }
    else{
        Q->arr[Q->front] =  item;
        Q->front = (Q->front+1)%N;
    }
    return item;
}



//print queue
void Print_Queue(Queue* Q){
    int temp = Q->front;
    while(temp != (Q->rear+1)%N){
        printf("%d\n",Q->arr[temp]);
        temp = (temp+1)%N;
        
    }
}


int main(){
    Queue* Q = (Queue*)malloc(sizeof(Queue));   

    //INITIALIZE VARIBLES
    Q->front = -1;
    Q->rear =-1;
    Q->current_student=-1;
    Q->last_token_issued=0;

    QUEUE_PUSH(Q,27);
    QUEUE_PUSH(Q,11);
    QUEUE_PUSH(Q,12);
    QUEUE_PUSH(Q,25);

    Print_Queue(Q);

    printf("------------------------\n");
    QUEUE_POP(Q);
    Print_Queue(Q);

}