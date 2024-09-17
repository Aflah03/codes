#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool CAN_JUMP(vector<int>& possible_jumps,int count){
    if(count>possible_jumps.size()-1) return false;
    if(count==possible_jumps.size()-1) return true;

    int w=0;

        for(int i=1;i<=possible_jumps[count];i++){
            // printf("this is run %d times", w++);
            if(CAN_JUMP(possible_jumps,i+count)==true)
                return true;
    }
    return false;
}
int main(){
    vector<int> possible_jumps={2,3,1,1,4}  ;
    int n = 0;
    cout << CAN_JUMP(possible_jumps,n);
}