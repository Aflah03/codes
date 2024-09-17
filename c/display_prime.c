#include<stdio.h>
#include<stdbool.h>
bool IsPriime(int num){
    if(num==1 || num ==0)
        return false;
    else{
        for(int i=2;i<=num/2;i++){
            if(num % i ==0)
                return false;
        }
        return true;
    }
}
int main(){
    int N;
    printf("Enter N");
    scanf("%d",&N);
    
    for(int i=1;i<N;i++){
        if(IsPriime(i)){
            printf("%d ",i);
        }

    }
    printf("Are prime");
}
