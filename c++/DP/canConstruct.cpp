#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool canConstruct(string target,vector<string>& wordBank,unordered_map<string,int>& memo){
    if(memo.find(target) != memo.end()) return memo[target];
    if(target=="") return true;

    for(string word: wordBank){
        if(target.find(word) ==0) //at 0 implies this word is a prefix of target
        {
            string suffix = target.substr(word.length()); // no second argument impleies upto end of target(form index word.length)
            if((canConstruct(suffix,wordBank,memo)) == true)
                return true;
        }
    }
    memo[target] = false;
    return false;
}

int main(){

     string target= "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef";
    vector<string> wordBank = {"e","ee","eee","eeee","eeeee","eeeeeeee","eeeeeeeeeee"};
    // string target= "abcdef";
    // vector<string> wordBank = {"ab","abc","cd","def","abcd"};
    unordered_map<string,int> memo;
    cout << canConstruct(target,wordBank,memo);


}       