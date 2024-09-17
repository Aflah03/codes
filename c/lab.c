#include<stdio.h>

void prime_check(int num){
    if(num==1){
        printf("Not a prime_no.");
        return;
    }
    int flag =0;
    for(int i=2;i<=num/2;i++){
        if(num %i==0){
            flag++;
            break;
        }
    }
    if(flag !=0 ){
        printf("Not a prie number\n");
    }
    else 
        printf("Prime Number\n");
}
void GreatestDivisor(int num){
     int greatest_divisor;
    int flag =0;
    for(int i=num/2;2;i--){
        if(num % i == 0){
            greatest_divisor = i;
            break;
        }
    GreatestDivisor(num);
            
    }
    printf("greatest divisor: %d\n",greatest_divisor);
}
int main(){
    int num;
    printf("enter number");
    scanf("%d",&num);
    GreatestDivisor(num);

    
    prime_check(num);

}