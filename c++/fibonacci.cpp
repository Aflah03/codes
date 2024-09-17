#include <cstddef>
#include <cstdio>
#include <iostream>
#include <bits/stdtc++.h>
#include <unordered_map>
using namespace std;

size_t fib(int n,map<int,size_t>& memo){
  if(memo.find(n) != memo.end()) return memo[n];

  if(n<=2) return 1;
  memo[n] =fib(n-1,memo) + fib(n-2,memo);
  return memo[n];
  
}
int main(){
  map<int,size_t> memo;
  char buf[100];
  cout << "Enter number";
  fgets(buf,100,stdin);
  int num;
  sscanf(buf,"%d",&num);

  fib(num,memo);
   for(auto number : memo){
    cout << number.second << " "<<endl;
  }
}
