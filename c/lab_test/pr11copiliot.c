#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int coeff; // coefficient
    int exp;   // exponent
    struct list *next;
} Node;

Node *getNode(int coeff, int exp) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error allocating memory");
        return NULL;
    }
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void PRINT_LIST(Node *head) {
    Node *temp = head->next;
    int count = 0;
    while (temp != NULL) {
        if (count != 0)
            printf(" + ");
        count++;
        printf("%dx^%d", temp->coeff, temp->exp);
        temp = temp->next;
    }
    printf("\n");
}

Node *INSERT_POLYNOMIAL() {
    Node *head = getNode(0, 0);
    Node *temp = head;
    int n;
    printf("Enter number of terms in the polynomial: \n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int coeff, exp;
        printf("Enter coefficient and exponent of term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        temp->next = getNode(coeff, exp);
        temp = temp->next;
    }
    return head;
}

Node *Add_Univariate(Node *poly1, Node *poly2) {
    Node *head = getNode(0, 0);
    Node *temp = head;
    Node *p1 = poly1->next;
    Node *p2 = poly2->next;

    while (p1 != NULL || p2 != NULL) {
        int coeff, exp;
        if (p1 != NULL && (p2 == NULL || p1->exp > p2->exp)) {
            coeff = p1->coeff;
            exp = p1->exp;
            p1 = p1->next;
        } else if (p2 != NULL && (p1 == NULL || p2->exp > p1->exp)) {
            coeff = p2->coeff;
            exp = p2->exp;
            p2 = p2->next;
        } else {
            coeff = p1->coeff + p2->coeff;
            exp = p1->exp;
            p1 = p1->next;
            p2 = p2->next;
        }
        temp->next = getNode(coeff, exp);
        temp = temp->next;
    }
    return head;
}

Node *MULTIPLY_WITHOUT_ADDING_ALL(Node *poly1, Node *poly2) {
    Node *result = getNode(0, 0);
    Node *temp1 = poly1->next;

    while (temp1 != NULL) {
        Node *temp2 = poly2->next;
        while (temp2 != NULL) {
            Node *newNode = getNode(temp1->coeff * temp2->coeff, temp1->exp + temp2->exp);
            Node *temp = result;
            while (temp->next != NULL && temp->next->exp > newNode->exp) {
                temp = temp->next;
            }
            if (temp->next != NULL && temp->next->exp == newNode->exp) {
                temp->next->coeff += newNode->coeff;
                free(newNode);
            } else {
                newNode->next = temp->next;
                temp->next = newNode;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return result;
}

int main() {
    Node *polynomial_1;
    Node *polynomial_2;
    Node *result;

    printf("Polynomial 1\n");
    polynomial_1 = INSERT_POLYNOMIAL();
    printf("Polynomial 2\n");
    polynomial_2 = INSERT_POLYNOMIAL();

    printf("Polynomial 1: \n");
    PRINT_LIST(polynomial_1);
    printf("\nPolynomial 2: \n");
    PRINT_LIST(polynomial_2);

    printf("Choose operation\n");
    printf("1- Addition\n");
    printf("2- Multiplication\n");
    int operation;
    scanf("%d", &operation);
    getchar();

    switch (operation) {
        case 1:
            printf("\nAdding polynomial 1 and 2: \n");
            result = Add_Univariate(polynomial_1, polynomial_2);
            PRINT_LIST(result);
            break;
        case 2:
            printf("Multiplying polynomials: \n");
            result = MULTIPLY_WITHOUT_ADDING_ALL(polynomial_1, polynomial_2);
            PRINT_LIST(result);
            break;
        case 3:
            return 0;
    }

    return 0;
}
