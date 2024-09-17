#include<stdio.h>
int sum_to_n(int  n){
    if(n==0)
        return 0;
    else    
        return n+ sum_to_n(n-1);
}
int main(){
    int n=6;
    printf("THE sum is %d",sum_to_n(n));   
}