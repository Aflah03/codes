#include <stdio.h>
#include <string.h>

int main(){
  char* names[10];// an array of 10 strings

  names[0] = "Aflah";
  //names[0][0] = 'J';//not possible , but mutable when assignesd using stdup

  names[1] = strdup("BABU");
  // error not possible  names[0][0] = 'B';
  printf("%s\n",names[0]);
  
  names[1][3] = 'J';
  names[1]++; // names[1] has BABJ stored , names[1] is pointing to the first character B , when ++ is used it points to next 
  //CHARACTER
  printf("%s\n",names[1]);

  // so each item in char* names[] is a string by itself
  
}
