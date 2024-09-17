#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool canSum(int targetSum,vector<int>& numbers,vector<int>& path,unordered_map<int,bool>& memo){
    if(memo.find(targetSum) != memo.end()) return memo[targetSum];
    if(targetSum==0) return true;
    if(targetSum<0) return false;

    for(auto num:numbers){
        int remainder = targetSum-num;
        if(canSum(remainder,numbers,path,memo) == true){ // even when it is not true this  statement is executeed and recursive call is made
        // if it returns true it returns to true and all call stack goes back to ture and finally to root node
            // memo[targetSum] = true;
             //true implies  we directly return back to root so no help by stroing it
            path.push_back(num);
            return true;
        }

        
    }
    memo[targetSum] = false;
    return false;
}

int main(){
    vector<int> numbers={7,14};
    vector<int> path;unordered_map<int,bool> memo;
    int targetSum =1414;
    if (canSum(targetSum,numbers,path,memo)){
        cout << "we can sum to "<<targetSum<< "using the numbers: ";
        for(int num: path){
            cout << num << " ";
        }
        cout << endl;
    }
    else{
        cout <<" it isnot possible to sum to target sum";
    }
}