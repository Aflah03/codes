#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int addDigits(int num) {
        int rem =0;
        int sum = 0;
        int count = 0;
        while(num>10){
            while(num>0){
                rem = num%10;
                sum +=  rem;
                num = num/10;
            }
            num = sum;
        }
        return  num;
    }


    int main(){
        // cout << addDigits(38);
        // string s = "Aflah muhammed";
        // cout << s.length();
        vector<string> summary;
        int num  =6;
        string s = to_string(num);
        // cout << *(summary.begin()); // import line to read again
        cout << s;
        summary.push_back("Hello");
    }
