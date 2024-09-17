#include<stdio.h>
#include<stdbool.h>
#include<ctype.h> // to get isalphanum()
bool IsPalindrome(char str[]){
    int i;
    for(i=0;str[i]!='\0';i++){}
    int length =i;
    printf("the length is : %d ",length);
    int left =0, right = length -1;
    while(left<right){  //same as iterating from o ot n/2 and comparing btw i an n-1-i; //IMP //IMP
        if(!isalnum(str[left]))
            left++;
        else if(!isalnum(str[right]))
            right--;

        else if(str[left] != str[right])
            return false;
        else{
            right--;
            left++;
        } //DOnt do full of if statements , bcs every  time we change a left or rifht valve we need to update it and check condition
        // also when two charractors are not alnum consecutively it will miss it , when if elif is not used
    }
    return true;
    
}
int main(){
    char str[100];
    printf("Enter the string: ");
    scanf("%[^\n]",str);
    bool check = IsPalindrome(str);
    if(check)
        printf("is pakindrome");

    // printf("The lenght is : %d\n",i);
    // int l = strlen(str);
    // printf("%d is the lenght",l);

    
}