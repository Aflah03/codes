#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct List {
    int data;
    struct List *next;
} Node;

Node *getNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error in allocating memory");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void SLL_INSERT_AT_END(Node *head, int item) {
    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = getNode(item);
}

int SLL_REMOVE_FROM_END(Node *head) {
    if (head->next == NULL) {
        printf("The list is empty\n");
        return -1;
    }
    Node *p = head->next;
    Node *q = head;
    while (p->next != NULL) {
        q = p;
        p = p->next;
    }
    q->next = NULL;
    int item = p->data;
    free(p);
    return item;
}

int SLL_REMOVE_FROM_FRONT(Node *head) {
    if (head->next == NULL) {
        printf("The list is empty\n");
        return -1;
    }
    Node *temp = head->next;
    head->next = temp->next;
    int item = temp->data;
    free(temp);
    return item;
}

void SLL_PRINT_LIST(Node *head) {
    Node *temp = head->next;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void stackOperations(Node *Shead) {
    int item, operation;
    while (true) {
        printf("1-Push\n2-Pop\n3-Print Stack\n4-Exit\nOption: ");
        scanf("%d", &operation);
        getchar();
        switch (operation) {
            case 1:
                printf("Enter number to push: ");
                scanf("%d", &item);
                getchar();
                SLL_INSERT_AT_END(Shead, item);
                printf("Pushed %d to the stack\n", item);
                break;
            case 2:
                item = SLL_REMOVE_FROM_END(Shead);
                if (item != -1) {
                    printf("Popped %d\n", item);
                }
                break;
            case 3:
                printf("The Stack is: ");
                SLL_PRINT_LIST(Shead);
                break;
            case 4:
                return;
            default:
                printf("Invalid option\n");
        }
        printf("--------------------------------\n");
    }
}

void queueOperations(Node *Qhead) {
    int item, operation;
    while (true) {
        printf("1-Enqueue\n2-Dequeue\n3-Print Queue\n4-Exit\nOption: ");
        scanf("%d", &operation);
        getchar();
        switch (operation) {
            case 1:
                printf("Enter number to enqueue: ");
                scanf("%d", &item);
                getchar();
                SLL_INSERT_AT_END(Qhead, item);
                printf("Enqueued %d onto the queue\n", item);
                break;
            case 2:
                item = SLL_REMOVE_FROM_FRONT(Qhead);
                if (item != -1) {
                    printf("Dequeued %d\n", item);
                }
                break;
            case 3:
                printf("The Queue is: ");
                SLL_PRINT_LIST(Qhead);
                break;
            case 4:
                return;
            default:
                printf("Invalid option\n");
        }
        printf("--------------------------------\n");
    }
}

int main() {
    Node *Shead = getNode(0);
    Node *Qhead = getNode(0);
    int choice;

    while (true) {
        printf("1-Stack\n2-Queue\n3-Exit\nChoose: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                stackOperations(Shead);
                break;
            case 2:
                queueOperations(Qhead);
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
