#include<stdio.h>
#include<stdlib.h>
#define MAX_NUM 10000

// typedef struct{
//     int number;
//     int count;
//     int index;
// }hash;
int main(){
    FILE *fp;
    int num,count,max_count =0,mode;
    // hash my_hash[100];
    int freq[MAX_NUM];
    //array to store frequencies

    fp = fopen("numbers.txt","r");
    if(fp==NULL){
        printf("Error in opening file");
        return 1;
    }

    while(fscanf(fp,"%d",&num)==1){
        if(num>=0 && num<MAX_NUM){
            freq[num]++;
            if(freq[num]>max_count){
                max_count = freq[num];
                mode = num;
            }
        }
        else{
            printf("Number is out of range: %d\n",num);

        }

    }
    fclose(fp);
    printf("The mode is %d",mode);
}