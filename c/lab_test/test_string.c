#include<stdio.h>
#include<string.h>
int main(){
    char arr[100];
    
    printf("Enter the text");
    fgets(arr,sizeof(arr),stdin);
    printf("\nthe text is : \n");
    for(int i=0;i<strlen(arr);i++)
        printf("%c",arr[i]);
}