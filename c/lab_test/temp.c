#include<stdio.h>
#include<stdlib.h>
#define MAX_NUM 100000
int main(){
    FILE* fp;
    int num,max_count=0,mode;

    int freq[MAX_NUM];
    fp =fopen("numbers.txt","r");

    while(fscanf(fp,"%d",&num)==1){
        if(num>=0 && num<MAX_NUM){
            freq[num]++;
            if(freq[num] >max_count){
                max_count = freq[num];
                mode = num;
            }
        } 
        else{
            printf("Number is out of range");
        }       
    }
    fclose(fp);
    printf("The mode is %d and the count is :%d",mode,max_count);

}