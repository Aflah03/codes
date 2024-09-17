#include <iostream>
using namespace std;
#include <bits/stdc++.h>
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m= matrix.size();
        int n= matrix[0].size();
        cout << "m:" <<m << " n:" << n<<endl;
        int mcurr =0;
        while(mcurr<=m-1){
            int low = 0;
            int high = n-1;
            int mid;
            while(low<=high){
                mid = (high+low)/2;
                if(matrix[mcurr][mid] ==target)
                    return true;
                else if(matrix[mcurr][mid] < target){
                    low = mid+1;
                }
                else high = mid-1;
            }
            mcurr++;
        }
        return false;
}
int main(){
vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
// vector<vector<int>> matrix = {{1,3}};
int target = 3;
int  x =searchMatrix(matrix,target);
  cout << x;
                     
}
