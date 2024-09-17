#include<stdio.h>
#include<stdlib.h>
typedef struct list{
    int data;
    struct list* next;
}Node;
Node* Start_SLL(){
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = 0;
    p->next = NULL;
    return p;
}
Node* GetNode(int value){
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = value;
    p->next = NULL;
    return p;
}
void ReturNode(Node* temp){
    
    free(temp);
}
void Print_SLL(Node* head){
    if( head->next== NULL) {
        printf("The list is empty\n");
        return;
        }
    Node* temp = head->next;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
void INSERT_AT_BEGINING(Node* head,int value){
    Node* p= GetNode(value);
    if(head->next  == NULL){
        head->next = p;
    }
    else{
        p->next = head->next;
        head->next = p;
    }
}
Node* SLL_Search(Node* head, int key){
    Node* temp = head->next;
    while(temp!= NULL){
        if(temp->data ==key){
            return temp;
        }
        temp = temp->next;
    }
    return 0;
}

int SLL_INSERT_AFTER_KEY(Node* head,int key,int value){
    Node* temp = SLL_Search(head,key);
    if(temp == NULL){
        return 0;//key is not present
    }
    else{
        Node* newNode = GetNode(value);
        if(newNode!=NULL){
        newNode->next = temp->next;
        temp->next = newNode;
        return 1;       }
        else{
            printf("Error in getting a node");
        } 
    }

}
void SLL_INSERT_AT_END(Node *head, int value) {
  Node *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  Node *newNode = GetNode(value);
  temp->next = newNode;
}

Node* SLL_REVERSE_LIST(Node* head){
    Node* curr = head->next;
    Node* prev = NULL;
    while(curr != NULL){
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev; //new head , thos wont wrok wtih header node
}

int SLL_DELETE_FRONT(Node* head){
    Node* temp = head->next;
    if(temp==NULL)
        return -1;
    else{
        int item;
        item = temp->data;
        if(temp->next ==NULL)  head->next = NULL;//if thiss line isnt wirtten a segmentation fault could occur if list has only one element
        if(temp->next !=NULL) head->next= temp->next;
        ReturNode(temp);

        return item;

    }
}
int SLL_DELETE_AFTER_KEY(Node* head,int key){
    Node* p = SLL_Search(head,key);
    if(p==NULL)
        return -1;//key not found
    else if(p->next== NULL){
        return -2; //key is at last inidex
    }
    else{
        Node*  q= p->next;
        (p->next) = (q->next);
        int item = q->data;
        ReturNode(q);
        return item;
    }
}
int SLL_DELETE_FROM_END(Node* head){
    Node* temp = head;
    Node* temp1 = head->next;
    if(temp1==NULL){
        return -1;
    }
    else{
        while(temp1->next!=NULL){
            temp1 = temp1->next;
            temp = temp->next;
        }
        int item = temp1->data;
        ReturNode(temp1);
        temp->next = NULL;
        return item;
    }
}
int main(){
    Node* head = Start_SLL();
    SLL_INSERT_AT_END(head,10);
    SLL_INSERT_AT_END(head,13);
    SLL_INSERT_AT_END(head,15);
    SLL_INSERT_AT_END(head,19);
    SLL_INSERT_AT_END(head,25);

    SLL_INSERT_AFTER_KEY(head,15,102);


    int h = SLL_DELETE_FRONT(head);
    // int x=SLL_DELETE_FROM_END(head);
    // x=SLL_DELETE_FROM_END(head);
    // printf("Enter a vlaue to search: ");
    // int key;
    // int key;
    // scanf("%d",&key);
    // Node* temp  = SLL_Search(head,key);

    // if(temp!= NULL)
    //     printf("Key found");
    // else printf("the key is not found");
    head =  SLL_REVERSE_LIST(head);
    Print_SLL(head);
    printf("%d",head->data);
    // printf("\nThe deleted value is : %d",x);

}