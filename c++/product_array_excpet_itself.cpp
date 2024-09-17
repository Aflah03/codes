#include<iostream>
#include<bits/stdc++.h>
using namespace std;
  vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        for(int i=0;i<n;i++)
            result.push_back(1);
        // for(int i=0;i<n-1;i++){
        //     result[i+1] = result[i]*nums[i];
        // }
        for(int i=n-1;i>0;i--){
            result[i-1] = result[i]*nums[i];
        }
        return result;
    }
int main(){
    // vector<int> nums = {1,2,3,4};
    // vector<int> result= productExceptSelf(nums);
    // for(int num: result){
    //     cout << num     << " ";
    // }
    // unordered_map
    unordered_set<int> set;

    // set.insert(5);
    // set.insert(7);
    // set.insert(4);
    // set.insert(3);
    // set.insert(3);

    // set.erase(3);
    // for(auto num:set){
    //     cout << num<< " ";
    unordered_map<int,string> map;
    // map[1] = "Aflah";
    // map[2] = "aflah";
    // int n = sqrt(14);
    // cout << n; 
    array<int,5> arr;
    arr.fill(0);
    for(auto num: arr){
        cout << num << " ";
    }

}