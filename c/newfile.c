#include<stdio.h>
int main(){
    FILE* fp = fopen("new.txt","r+");

    int num;
    fscanf(fp,"%d",&num);
    printf("%d",num);

    fseek(fp,0,0);
    fprintf(fp,"%d",25);
    fseek(fp,123,0);
    fprintf(fp,"%d",27);

    fclose(fp);
}