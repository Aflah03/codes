#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main(){

    //2d vector array is implemented as vecotr<vector<int>> vect

    vector<vector<int>> result= {{1,2},{2,3}}; 
    for(auto num: result){
        cout << num;
    }
}