#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int countConstruct(string target,vector<string>& wordBank,unordered_map<string,int>& memo){
    if(memo.find(target) != memo.end()) memo[target];
    if(target =="") return 1; 

    int totalCount = 0;
    for(string word: wordBank){
        if(target.find(word)==0){
            int numWaysForRest = countConstruct(target.substr(word.length()),wordBank,memo);
            totalCount += numWaysForRest;
        }
    }
    memo[target] = totalCount;                              
    return totalCount;
}
int main(){
    vector<string> wordBank;
    unordered_map<string,int> memo;

    string target = "abcdef";
    wordBank ={"purp","abc","d","def","cd","ef","ab","c"};

    cout << countConstruct(target,wordBank,memo);
}