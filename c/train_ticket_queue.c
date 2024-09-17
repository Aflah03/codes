#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#define N 20
typedef struct{
    int number_of_forms;
    int token_number;
}Passenger;
typedef struct{
    int front,rear;
    int arr[N];
    int last_token_issued;
}Queue;

int PUSH_TO_QUEUE(Queue* Q,int item){
    if((Q->rear+1)%N  == Q->front)
        return -1;
    else if(Q->front ==-1){
        Q->front =0;
        Q->rear =0;
        
    }
    else{
        Q->rear = (Q->rear+1)%N;
    }
    Q->arr[Q->rear] = item;
    return 1;
}

int POP_FROM_QUEUE(Queue* Q){
    int item;
    if(Q->front ==-1){
        return INT_MIN;
    }
    else if(Q->front ==Q->rear){
        item = Q->arr[Q->front];
        Q->front=-1;
        Q->rear=-1;
    }
    else{
        item =Q->arr[Q->front];
        Q->front = (Q->front+1)%N;
    }
    return item;
}
void PRINT_QUEUE(Queue* Q){
    int temp = Q->front;
    while(temp !=(Q->rear+1)%N ){
        printf("%d ",Q->arr[temp]);
        temp = (temp+1)%N;
    }
}
int main(){
    Queue* Q = (Queue*)malloc(sizeof(Queue));
    Passenger P[20];
    Q->last_token_issued=0;
    Q->front=-1;
    Q->rear=-1;
    int x;
    int passenger_number =0;
    int passenger_at_front_of_queue = 0;
    /********************************************************** */
    //check if P is wroking
    // P[0].number_of_forms =5;
    // printf("Enter a number");
    // scanf("%d",&P[0].number_of_forms);
    // printf("No fo forms in p[0] is %d",P[0].number_of_forms);

    /********************************************************** */
    printf("1-GET A TOKEN\n");
    printf("2-SERVE A TICKET\n");
    printf("3-\n");
    printf("4-The current customer being served\n");
    printf("5-Number of customers waiting\n");
    printf("6-List all customers in the queue with the number of forms they have\n");
    printf("7-EXIT\n");
    while(1){
    printf("-------------------------------------------------------------\n");
        printf("CHOOSE!!\n");
        
        scanf("%d",&x);
    
    switch (x)
    {
    case 1:
        passenger_number++;
        if(passenger_number==1) 
            passenger_at_front_of_queue =1;
        printf("Enter the number of tickets: ");
        scanf("%d",&P[passenger_number].number_of_forms);
        Q->last_token_issued++;
        PUSH_TO_QUEUE(Q,Q->last_token_issued);
        P[passenger_number].token_number = Q->last_token_issued;
        printf("assigned token number %d, no. of forms: %d\n",Q->last_token_issued,P[passenger_number].number_of_forms);
        
        /* code */
        break;
    case 2:
        POP_FROM_QUEUE(Q);
        printf("Person with token number %d has been served a ticket\n",P[passenger_at_front_of_queue].token_number);
        P[passenger_at_front_of_queue].number_of_forms--;
        if(P[passenger_at_front_of_queue].number_of_forms !=0){
          PUSH_TO_QUEUE(Q,Q->last_token_issued++);
        printf("assigned token number %d, no. of forms: %d\n",Q->last_token_issued,P[passenger_at_front_of_queue].number_of_forms);

        }
        break;
    
    case 3:
        break;
    case 7:
        return 0;

    }//switch
    printf("----------------------------------------------------------\n");
    }//while
}
