#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//hash for pair as key in unordered map , which isnt defined in c++ stl, pass this as third stuff while creating unoordered map
struct hash_pair {
    size_t operator()(const pair<int, int>& p) const {
        // A simple hash combining both elements of the pair
        return hash<int>()(p.first) ^ hash<int>()(p.second);
    }
};

int gridTraveler(int m,int n,unordered_map<pair<int,int>,int,hash_pair>& memo){
    pair<int,int> p1={m,n};
    pair<int,int> p2={n,m};
    if(memo.find(p1) != memo.end()) return memo[p1];
    if(memo.find(p2) != memo.end()) return memo[p2];

    if(m==0 || n==0) return 0;
    if(m==1 && n==1) return 1;

    memo[{m,n}] = memo[{n,m}] =  gridTraveler(m-1,n,memo) + gridTraveler(m,n-1,memo);

    return memo[{m,n}];
}
int main(){
    unordered_map<pair<int,int>,int,hash_pair> memo;
    int m,n;
    cout << "How many ways can you move through a m*n grid ?: "<< endl << "enter m and n";
    cin >> m >> n;
    cout << gridTraveler(m,n,memo);
}