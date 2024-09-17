#include<stdio.h>
int main(){
    FILE* fptr = fopen("test.txt","a");

    if(fptr == NULL){
        printf("error in opening file");
        
    }
    else{
    
    fprintf(fptr,"\nThis line is appended using //\n//");
    
    fclose(fptr);

    }
    return 0;
}