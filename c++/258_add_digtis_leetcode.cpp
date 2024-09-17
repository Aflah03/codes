#include<iostream>
using namespace std;
int addDigits(int num) {
        int rem =0;
        int sum = 0;
        int count = 0;
        while(num>10){
            int n = num;
        cout<<count++ << ":vlaue of num at line 9 is "<< num<<endl;
            while(n>0){
                rem = n%10;
        cout <<count++ << ":vlaue of rem at line 12 is "<< rem<<endl;
                sum = (sum*10) + rem;
                n = n/10;
            }
            num = sum;
        }
        return  num;
    }


    int main(){
        cout << addDigits(38);
    }