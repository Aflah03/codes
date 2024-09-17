#include <stdio.h>
#include <string.h>
int main(){
  char arr[100];
  printf("enter the string");
  fgets(arr,100,stdin);
  arr[strcspn(arr,"\n")]='\0';

  char hash[26];
  for(int i=0;i<26;i++){
    hash[i]=0;
  }
  for(int i=0;strlen(arr);i++){
    if(arr[i]<='a' && arr[i]>='z'){
      hash[arr[i]-96]++;
    }
  }
  
  int max=0;

  for(int i=0;i<26;i++){
    if(hash[i]>max)
        max =i;
  }
  printf("the most occuring word is : %c",hash[max]+96);
}
