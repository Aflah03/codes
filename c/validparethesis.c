// #include<stdio.h>
// #include<string.h>

// //successfull
// int main(){
//     int right_parenthesis =0;
//     int left_parenthesis=0;

//     char expression[]= "())(";
//     for(int i=0;i<strlen(expression);i++){
//         if(right_parenthesis>left_parenthesis)
//         {
//         printf("Invlaid");
//         return 0;
//         }

//         if(expression[i] == '(')
//             left_parenthesis++;
//         else if(expression[i]==')')
//         {
            
//             left_parenthesis--;
//         }
//     }
//     if(left_parenthesis==0)
//         printf("valid\n");
//     else 
//         printf("Invalid\n");
    
    
// }


//Code with added ignore anything other than  paranthesis, also support for '{' '}' braces added

//-----------------------------------------------------------------------------------

// #include<stdio.h>
// #include<string.h>
// #include<stdbool.h>

// bool Isparanthesis(char C){
//     if(C == '(' || C== ')' || C=='{'  || C=='}')
//         return true;
//     return false;
// }
// int main(){
//     // int right_parenthesis =0;
//     int left_braces=0;
//     // int right_braces=0;
//     int left_parenthesis=0;
    
//     char expression[]= "bgf{fkb((kndgfj)((2+3)dfjfd())b((jn()bfdjbfd)))){}}";
//     for(int i=0;i<strlen(expression);i++){
//         if(!Isparanthesis)
//             continue;
        
//         // if(right_braces > left_braces || right_parenthesis>left_parenthesis){
//         //     printf("invalid");
//         //     return 0;
//         // }

//         if(expression[i] =='{')
//             left_braces++;
//         else if(expression[i] =='}')
//             left_braces--;
//         if(expression[i] == '(')
//             left_parenthesis++;
//         else if(expression[i]==')')
//         {
            
//             left_parenthesis--;
//         }
//     }
//     if(left_parenthesis==0 )
//         printf("valid\n");
//     else 
//         printf("Invalid hn");
    
    
// }

#include<stdio.h>
#include<string.h>


int main(){
    int left_paranthesis =0;
    int right_paranthesis =0;
    char str[20] ;
    printf("Enter the string: ");
    scanf("%[^\n]%*c", str);
  
    int n =strlen(str); 
   
    for(int i=0;i<n;i++){
        if(right_paranthesis> left_paranthesis){
            printf("Invalid");
            return 0;
        }
        else if(str[i] == '(')
            left_paranthesis++;
        else if(str[i] == ')')
            right_paranthesis++;
        else    
            continue;
    }
    if(left_paranthesis == right_paranthesis)
        printf("valid");
    else
        printf("Invlaid");
}


