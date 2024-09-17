#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public: 
    unordered_map<int,int> memo;
    int coinChange(vector<int>& coins,int amount,unordered_map<int,int>& memo){
        if(memo.find(amount)!= memo.end()) return memo[amount];
        if(amount==0) return 1;
        if(amount < 0) return 0; 
        memo[amount]=0;
        int total_count =0;
        for(int i=0;i<coins.size();i++){
            int remainder = amount-coins[i];
            int Waysforrest = coinChange(coins,remainder,memo);
            if(Waysforrest< memo[remainder])
                memo[remainder] = Waysforrest;
            total_count+=Waysforrest;
            if(memo[amount] < total_count)  
                memo[amount] = total_count;
            
        }
        return memo[amount];
    }
};
int main(){
    Solution solution;
    int amount = 5;
    vector<int> coins = {1,2};
    cout << solution.coinChange(coins,amount,solution.memo);
}