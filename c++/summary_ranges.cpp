 #include<iostream>
#include<bits/stdc++.h>
using namespace std;
 vector<string> summaryRanges(vector<int>& nums) {
        vector<string> summary;
        int i =0;
        while(nums.size()>i){
            if(i== nums.size()-1){
                summary.push_back(to_string(nums[i]));
                i++;
            }
            else if(nums[i]+1 != nums[i+1]){
                string s = to_string(nums[i]);
                summary.push_back(s);
                i++;
            }
            else{
                int j =i;
                cout << "1.value of i is :" <<i<< ", value of j is"<< j<<endl;
                while( j<(nums.size()-1) && (nums[j]+1 == nums[j+1]) ){
                    j++;
                } 
                string s= to_string(nums[i]) + "->" + to_string(nums[j]);
                summary.push_back(s);
                i =  j+1;
                cout << "1.value of i is :" <<i<< ", value of j is"<< j<<endl;
            }
        }
        return summary;
    }
    int main(){
        vector<int> nums = {1,3};
        // vector<int> nums = {0,1,2,4,5,7};
        vector<string> summary = summaryRanges(nums);
        for(auto stuff: summary)
            cout << stuff << " ";
    }