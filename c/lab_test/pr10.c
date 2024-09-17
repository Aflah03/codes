#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    if (temp->subject == key) {
      return temp;
    }
    temp = temp->next;
  }
  return NULL;
}
book *Search_for_Subject(book *head, char *item) {
  book *temp = head->next;
  while (temp != NULL) {
    if (temp->subject == item)
      return temp;
    printf("Found in search of subject!!\n");
    temp = temp->next;
  }
  return NULL;
}
book *ADD_NEW_BOOK(book *head) {
  // entering details of book
  char arr[100];

  book *newBook = (book *)malloc(sizeof(book));
  newBook->next = NULL;
  newBook->prev = NULL;
  printf("Enter title of the book:");
  fgets(arr, 100, stdin);
  arr[strcspn(arr, "\n")] = '\0';
  newBook->title = strdup(arr);

  printf("Enter author name:");
  fgets(arr, 100, stdin);
  arr[strcspn(arr, "\n")] = '\0';
  newBook->author = strdup(arr);

  printf("Enter subject:");
  fgets(arr, 100, stdin);
  arr[strcspn(arr, "\n")] = '\0';
  newBook->subject = strdup(arr);

  printf("Enter shelf number and edition: ");
  scanf("%d %d", &newBook->shelfNumber, &newBook->edition);


  // adding book to linked list logic

  if (head->next == NULL) {
    head->next = newBook;
    return newBook;
  } else {
    // search and find if there is any that match this books subject
    // then if does not match add the book to end of the DLL(to the begingin is
    // also fine)
    /*if any of the subjects matches , we need to compare the strcmp values of
     * authors names of the books having the same subject namme , and find the
     * one with the author having least stcmp vlaue , if strcmp is -ve add
     * newBOOk to left if strcmp is postive add newBook to right
     */
    book *subjectPositoin = Search_for_Subject(head, newBook->subject);
    if (subjectPositoin ==NULL) // no matching subject add , newBook to beginging of list
    {
        newBook->next = head->next;
        head->next = newBook;
      newBook->prev = head;

    } else { // there is mathching subject , so we need to insert by also
             // chekcing the alphabetical order
          int min_value=79787980;
        book* temp = subjectPositoin;
        book* insertposition;
      while(strcmp(temp->subject, newBook->subject) == 0){ //temp->subject == newBook->subject, this does not wrok for strings
        int value;
        value = strcmp(newBook->author,temp->author);
        if(value< min_value){
          insertposition = temp; 
        }
        temp = temp->next;
      }
      if(min_value < 0){
          //insert to left of insertPostion
          insertposition->prev->next = newBook;
          newBook->next = insertposition;
          newBook->prev = insertposition->prev;
          insertposition->prev = newBook;
          
      }
      else {
      //insert to right of insert positoninsertposition
        newBook->next = insertposition->next;
        newBook->prev = insertposition;
        insertposition->next = newBook;
      }

    }
  }
  return NULL;
}
void Print_book_details(book *p) {
  printf("Details:\n");
  printf("Title: %s\n", p->title);
  printf("Author: %s\n", p->author);
  printf("Subject: %s\n", p->subject);
  printf("Edition: %d\n", p->edition);
  printf("ShelfNumber: %d\n", p->shelfNumber);
}

  void print_library(book* head){

  book* p = head->next;
  if(p==NULL){
    printf("Library is empty");
    return;
  }
  printf("LIBRARY!!\n");
  int book_number =0;
  while(p!= NULL){
   book_number++;
    printf("book: %d\n",book_number);
  printf("Title: %s\n", p->title);
  printf("Author: %s\n", p->author);
  printf("Subject: %s\n", p->subject);
  printf("Edition: %d\n", p->edition);
  printf("ShelfNumber: %d\n", p->shelfNumber);
    printf("-----------------------------------------------\n");
    p = p->next;
  }
}

char *REMOVE_BOOK(book *);
int main() {
  book *head = (book*)malloc(sizeof(book));
  head->title = strdup("none");
  head->author = strdup("none");
  head->subject = strdup("none");
  // ADD_NEW_BOOK(head);
  // Print_book_details(head->next);

  printf("1-  insert a book: \n");
  printf("2-  print library: \n");
  printf("3-  EXIT: \n");
  int choice = 0;
  while(1){
    printf("enter choice: ");
    scanf("%d",&choice);
    getchar();

    switch (choice) {
    
      case 1:
        ADD_NEW_BOOK(head);
        break;
      case 2:
      
        print_library(head);
        break;
      case 3:
        return 0;
      
    }
  }
}
