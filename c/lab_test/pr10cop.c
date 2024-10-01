#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct list {
    char *title;
    char *author;
    int edition;
    char *subject;
    int shelfNumber;
    struct list *next;
    struct list *prev;
} book;

book *getNode(char *title, char *author, int edition, char *subject, int shelfNumber) {
    book *newBook = (book *)malloc(sizeof(book));
    if (newBook == NULL) {
        printf("Error in allocation memory!!");
        return NULL;
    }
    newBook->title = strdup(title);
    newBook->author = strdup(author);
    newBook->edition = edition;
    newBook->subject = strdup(subject);
    newBook->shelfNumber = shelfNumber;
    newBook->next = NULL;
    newBook->prev = NULL;
    return newBook;
}

void PRINT_LIBRARY(book *head) {
    book *temp = head->next;
    if (temp == NULL) {
        printf("Library is empty\n");
        return;
    }
    printf("LIBRARY!!\n");
    int book_number = 0;
    while (temp != NULL) {
        book_number++;
        printf("\nBOOK : %d\n", book_number);
        printf("Title: %s\n", temp->title);
        printf("Author: %s\n", temp->author);
        printf("Subject: %s\n", temp->subject);
        printf("Edition: %d\n", temp->edition);
        printf("Shelf Number: %d\n", temp->shelfNumber);
        printf("-----------------------------------------------");
        temp = temp->next;
    }
    printf("\n");
}

book *SEARCH_SUBJECT(book *head, char *item) {
    book *temp = head->next;
    while (temp != NULL) {
        if (strcasecmp(temp->subject, item) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

int REMOVE_BOOK(book *head, char *item) {
    book *temp = head->next;
    while (temp != NULL) {
        if (strcasecmp(temp->title, item) == 0) {
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
            temp->prev->next = temp->next;
            free(temp->title);
            free(temp->author);
            free(temp->subject);
            free(temp);
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

book *ADD_NEW_BOOK(book *head) {
    char title[100], author[100], subject[100];
    int edition, shelfNumber;

    printf("Enter book title: ");
    fgets(title, 100, stdin);
    title[strcspn(title, "\n")] = '\0';

    printf("Enter author name: ");
    fgets(author, 100, stdin);
    author[strcspn(author, "\n")] = '\0';

    printf("Enter subject: ");
    fgets(subject, 100, stdin);
    subject[strcspn(subject, "\n")] = '\0';

    printf("Enter edition and shelf number: ");
    scanf("%d %d", &edition, &shelfNumber);
    getchar();

    book *newBook = getNode(title, author, edition, subject, shelfNumber);
    if (newBook == NULL) {
        return NULL;
    }

    book *position = SEARCH_SUBJECT(head, newBook->subject);
    if (position == NULL) {
        newBook->next = head->next;
        if (head->next != NULL) {
            head->next->prev = newBook;
        }
        head->next = newBook;
        newBook->prev = head;
    } else {
        book *insertPosition = position;
        while (insertPosition->next != NULL && strcasecmp(insertPosition->next->subject, newBook->subject) == 0) {
            if (strcasecmp(newBook->author, insertPosition->author) < 0) {
                break;
            }
            insertPosition = insertPosition->next;
        }
        newBook->next = insertPosition->next;
        if (insertPosition->next != NULL) {
            insertPosition->next->prev = newBook;
        }
        insertPosition->next = newBook;
        newBook->prev = insertPosition;
    }
    return newBook;
}

int SEARCH_BOOK(book *head, char *item) {
    book *temp = head->next;
    while (temp != NULL) {
        if (strcmp(temp->title, item) == 0) {
            return temp->shelfNumber;
        }
        temp = temp->next;
    }
    return -1;
}

int main() {
    book *head = (book *)malloc(sizeof(book));
    head->title = strdup("none");
    head->author = strdup("none");
    head->subject = strdup("none");
    head->next = NULL;
    head->prev = NULL;

    char arr[100];
    int choice;

    printf("1- Add a book\n");
    printf("2- Print details of books\n");
    printf("3- Remove a book\n");
    printf("4- Get shelf number of a book\n");
    printf("5- EXIT\n");

    while (1) {
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                ADD_NEW_BOOK(head);
                break;
            case 2:
                PRINT_LIBRARY(head);
                break;
            case 3:
                printf("Enter the name of the book to remove: ");
                fgets(arr, 100, stdin);
                arr[strcspn(arr, "\n")] = '\0';
                if (REMOVE_BOOK(head, arr)) {
                    printf("Removed book: %s\n", arr);
                } else {
                    printf("Book not found\n");
                }
                break;
            case 4:
                printf("Enter the book title to search for it: ");
                fgets(arr, 100, stdin);
                arr[strcspn(arr, "\n")] = '\0';
                int shelfNumber = SEARCH_BOOK(head, arr);
                if (shelfNumber != -1) {
                    printf("Book is at: %d\n", shelfNumber);
                } else {
                    printf("No book named %s in the library\n", arr);
                }
                break;
            case 5:
                return 0;
        }
    }
}
