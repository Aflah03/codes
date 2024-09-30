#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void SLL_PRINT_LIST_IN_REVERSE_ORDER_USING_RECURSION(Node *temp) {
    if (temp == NULL)
        return;
    SLL_PRINT_LIST_IN_REVERSE_ORDER_USING_RECURSION(temp->next);
    printf("%d", temp->data);
}

void SLL_PRINT_LIST(Node *head) {
    Node *temp = head->next;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

Node *CONVERT_TO_SLL(char arr[]) {
    Node *head = getNode(0);
    Node *temp = head;
    for (char *item = arr; *item != '\0'; item++) {
        if (*item != ' ') {
            int value = *item - '0';
            temp->next = getNode(value);
            temp = temp->next;
        }
    }
    return head;
}

Node *CONVERT_TO_SLL_IN_REVERSE(char arr[]) {
    Node *head = getNode(0);
    for (int i = strlen(arr) - 1; i >= 0; i--) {
        if (arr[i] != ' ') {
            int value = arr[i] - '0';
            SLL_INSERT_AT_END(head, value);
        }
    }
    return head;
}

Node *ADD_TWO_SLL(Node *list1, Node *list2) {
    Node *resultHead = getNode(0);
    Node *temp1 = list1->next;
    Node *temp2 = list2->next;
    Node *temp = resultHead;
    int carry = 0;

    while (temp1 != NULL || temp2 != NULL || carry) {
        int sum = carry;
        if (temp1 != NULL) {
            sum += temp1->data;
            temp1 = temp1->next;
        }
        if (temp2 != NULL) {
            sum += temp2->data;
            temp2 = temp2->next;
        }
        carry = sum / 10;
        temp->next = getNode(sum % 10);
        temp = temp->next;
    }
    return resultHead;
}

int main() {
    char arr[100];
    printf("Enter the first Number:\n");
    fgets(arr, 100, stdin);
    arr[strcspn(arr, "\n")] = '\0';
    Node *number1 = CONVERT_TO_SLL_IN_REVERSE(arr);

    printf("Enter the Second Number:\n");
    fgets(arr, 100, stdin);
    arr[strcspn(arr, "\n")] = '\0';
    Node *number2 = CONVERT_TO_SLL_IN_REVERSE(arr);

    Node *result = ADD_TWO_SLL(number1, number2);
    printf("Result: ");
    SLL_PRINT_LIST_IN_REVERSE_ORDER_USING_RECURSION(result->next);

    return 0;
}
