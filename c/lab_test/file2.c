#include<stdio.h>

int main(){
    FILE *fpn, *fpe,*fpo;
    int num,count,i;
    fpn = fopen("numbers.txt","w");
    fpe = fopen("even.txt","w");
    fpo = fopen("odd.txt","w");

    if(fpn ==NULL || fpe== NULL || fpo==NULL){
        printf("sorry error in openig file: ");

    }
    else{

        printf("How many integers do you want to enter?\n");
        scanf("%d",&count);
        printf("Enter the numbers: ");
        for(int i=0;i<count;i++){
            scanf("%d",&num);
            putw(num,fpn);
        }
        
    }
        fclose(fpn);
        fpn = fopen("numbers.txt","r");

        num = getw(fpn);


        while(num!= EOF){
            if(num%2==0)
                putw(num,fpe);
            else
                putw(num,fpo);
            num = getw(fpn);

        }
        fclose(fpo);
        fclose(fpe);

        fpe = fopen("even.txt","r");
        fpo = fopen("odd.txt","r");

        printf("Contents of the file with even number: ");
        num = getw(fpe);
        while(num!= EOF){
            printf("%d ",num);
            num = getw(fpe);
        }
        printf("\ncontents of file with odd numbers: ");
        num = getw(fpo);
        while(num != EOF){
            printf("%d",num);
            num = getw(fpo);
        }
        fclose(fpe);
        fclose(fpn);
        fclose(fpo);


}