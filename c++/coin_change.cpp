#include <cmath>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int coinChange(vector<int> coins,int amount,unordered_map<int,int> memo){
    if(memo.find(amount)  != memo.end()) return memo[amount];
    if(amount ==0) return 1;
    if(amount <0) return 0;
    
  int shortest_way = 0;
  int total_count=0;
  for(int i=0;i<3;i++){
    int remainder = amount- coins[i];
    int remainderWays = coinChange(coins,remainder,memo);
    total_count +=remainderWays;
    
    
     }
  if(shortest_way==0 || total_count< shortest_way )
    shortest_way = total_count;
  memo[amount] = total_count;
  return shortest_way;
}
int main(){
  vector<int> coins={1,2,5};
  int amount  = 11;

  unordered_map<int,int> memo;
  int N = coinChange(coins,amount,memo);
  cout << "No of coins required is : " << N << endl;

}
