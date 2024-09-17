#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int countClimbStairs(int n,unordered_map<int,int>& memo){
    if(memo.find(n) !=memo.end() ) return memo[n];
    if(n==0) return 1;
    if(n<0) return 0;
    memo[n] = countClimbStairs(n-1,memo) + countClimbStairs(n-2,memo);
    return  memo[n];
}

int main(){
    vector<int> dp(5);
    for(auto num: dp)
        cout << num<< " ";
        unordered_set<int> set;
        set.insert(5);
        set.insert(2);
        set.insert(3);
}
