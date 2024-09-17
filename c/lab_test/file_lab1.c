#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE* fp = fopen("input.txt","r+");
    int num,check;
    int location,count= 0,mode,max_count=0;
    if(fp == NULL){
        printf("error in opening file!");
        return 0;
    }
    else{
        while(fscanf(fp,"%d",&num)!= EOF){ // this moves fp by one point
            location = ftell(fp);
            rewind(fp);
            while(feof(fp)==0){
                fscanf(fp,"%d",&check);
                if(num == check){
                    count++;
                }
            }
            if(count > max_count){
                max_count = count;
                mode = num;
            }
            count =0;
            fseek(fp,location,0);
        }
    }
        printf("The mode is %d",mode);
}