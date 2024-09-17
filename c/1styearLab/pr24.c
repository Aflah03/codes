#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool isPalindrome(char* s){
  int l = 0;
  int r = 0;
  char* temp=s;
  while(*temp!= '\0'){
    r++;
    temp++;
  }
  r = r-1;
  int flag=0;
  while(l<r){
    if(s[l] !=s[r])
      return false;
    r--;
    l++;
  }
  return  true;
}
int main(){

    char arr[100];
    printf("Enter the string: ");
    fgets(arr,100,stdin);
    arr[strcspn(arr,"\n")]='\0';
  printf("you enterd the string %s\n",arr);

    if(isPalindrome(arr))
      printf("entered string is palindrome");
    else
      printf("entered string is not a palindrome");

    
}
