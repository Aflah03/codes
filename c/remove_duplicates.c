#include<stdio.h>
int main(){
    int arr[]= {1,1,1,1,1,2,12,12,12,13,11,2,3,3,3,3,4,4,4,4,5,7};
    int i=0,j=1;int index=1;
    int n= sizeof(arr)/sizeof(arr[0]);
    while(j<n){
        if(arr[i] != arr[j]){
            arr[i+1] = arr[j];
            i++;
        }
        j++;
    }
    for(int k=0;k<=i;k++){
        printf("%d ",arr[k]);
    }
}

