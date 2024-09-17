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
book *Search_DLL(book *head, char *key) {
  book *temp = head->next;
  while (temp != NULL) {
    if (strcasecmp(temp->subject, key) == 0) {
      return temp;
    }
    temp = temp->next;
  }
  return NULL;
}
// book* Search_insert_postion()

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
    printf("Titile: %s\n", temp->title);
    printf("Author: %s\n", temp->author);
    printf("Subject: %s\n", temp->subject);
    printf("edition: %d\n", temp->edition);
    printf("shelfNumber: %d\n", temp->shelfNumber);
    printf("-----------------------------------------------");
    temp = temp->next;
  }
  printf("\n");
}
book *SEARCH_SUBJECT(book *head, char *item) {
  book *temp = head->next;

  while (temp != NULL) {
    if (strcasecmp(temp->subject, item) == 0) {
      printf("Mathcing subject found\n");
      return temp;
    }
    temp = temp->next;
  }
  return NULL;
}
int REMOVE_BOOK(book* head,char* item){
  book* temp = head->next;
  while(temp != NULL){
    if(strcasecmp(temp->title,item)==0){
      //remove the Node
      if(temp->next!= NULL){
        temp->next->prev = temp->prev;
      }
          temp->prev->next = temp->next;
      return 1;
    }
    temp = temp->next;
  }
  return 0;
}
book *ADD_NEW_BOOK(book *head) {
  char arr[100];
  book *newBook = (book *)malloc(sizeof(book));
  if (newBook == NULL) {
    printf("Error in allocation memeory !!");
    return NULL;
  }
  newBook->next = NULL;
  newBook->prev = NULL;
  printf("Enter book title: ");
  fgets(arr, 100, stdin);
  arr[strcspn(arr, "\n")] = '\0';
  newBook->title = strdup(arr);

  printf("Enter author name:");
  fgets(arr, 100, stdin);
  arr[strcspn(arr, "\n")] = '\0';
  newBook->author = strdup(arr);

  printf("Enter Subject:");
  fgets(arr, 100, stdin);
  arr[strcspn(arr, "\n")] = '\0';
  newBook->subject = strdup(arr);

  printf("Enter edition and shelfNumber:");
  scanf("%d %d", &newBook->edition, &newBook->shelfNumber);
  getchar();

  // now insert book logic
  book *position = SEARCH_SUBJECT(head, newBook->subject);
  if (position == NULL) {
    // no matching subject so, insert at beginging
    newBook->next = head->next;
    if (head->next != NULL)
      head->next->prev = newBook;
    newBook->prev = head;
    head->next = newBook;
  } else {
    // matchign subject found so sort and add
    int flag = 0;
    book *insertpostion = position;
    while (insertpostion->next != NULL &&
           strcasecmp(insertpostion->next->subject, newBook->subject) == 0) {
      if (strcasecmp(newBook->author, insertpostion->author) < 0) {
     
        newBook->next = insertpostion;
        newBook->prev = insertpostion->prev;
        if (insertpostion->prev != NULL)
          insertpostion->prev->next = newBook;
        insertpostion->prev = newBook;
        flag = 1;
        break;

         }
        insertpostion = insertpostion->next;
      }
    //this check of flag==0 is pretty important , bcs otherwise we could get into an infinte loop
      if(flag==0 && strcasecmp(newBook->subject,insertpostion->subject)==0 && strcmp(newBook->author,insertpostion->author)<0){

      //same code as above for the edge case when only we have to insert before the last node of that subject 
      //in tha aboive while loop it also checksk if insertpositon->next->subject so edge case is mmissed
        newBook->next = insertpostion;
        newBook->prev = insertpostion->prev;
        if (insertpostion->prev != NULL)
          insertpostion->prev->next = newBook;
        insertpostion->prev = newBook;
        flag = 1;
    }


      if (flag == 0) {


        newBook->prev = insertpostion;

        newBook->next = insertpostion->next;
        if (insertpostion->next != NULL)
          insertpostion->next->prev = newBook;
        insertpostion->next = newBook;
      }
    }
    return newBook;
  }
int SEARCH_BOOK(book* head,char* item){
  book* temp = head->next;
  while(temp != NULL){
    if(strcmp(temp->title,item)==0)
        return temp->shelfNumber;
    temp = temp->next;
  }
  return -1;

}
int main() {
  book *head = (book *)malloc(sizeof(book));
  head->title = strdup("none");
  head->author = strdup("none");
  head->subject = strdup("none");

  char arr[100];
  printf("1- Add a book\n");
  printf("2- Printf details of a book\n");
  printf("3- remove a book\n");
  printf("4-Get shelfNumber of a book\n");
  printf("5- EXIT\n");

  int choice;
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
        //remove a book 
        printf("Enter the name of the book to remove: ");
        fgets(arr,100,stdin);
        
        arr[strcspn(arr,"\n")]='\0';
        printf("you requested to remove: %s\n",arr);
        // if(REMOVE_BOOK(head,arr)==0){
        //   printf("book not found");
        // }
        // else{
        //   printf("Book removed succeessfully");
        // }
        if(REMOVE_BOOK(head,arr)){
          printf("Removed book : %s\n",arr);
        }
        else{
          printf("book not found\n");
        }
      break;
    case 4:
        printf("Enter the book title to search for it: ");

        fgets(arr,100,stdin);
        arr[strcspn(arr,"\n")]='\0';

        int shelfNumber = SEARCH_BOOK(head,arr);
        if(shelfNumber!=-1){
          printf("Book is at: %d\n",shelfNumber);
        }
        else{
          printf("No book named %s in the library\n",arr);
        }
      break;
    case 5:
      return 0;
    }
  }
}
