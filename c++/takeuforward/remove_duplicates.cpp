#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int remove_duplicates(int arr[],int n){
        set<int> set1 ;
        for(int i=0;i<n;i++)
            set1.insert(arr[i]);
        int k = set1.size();
        int j=0;
        for(int x: set1){
            arr[j++] = x;
        }
        return k;

}

int main(){
    int arr[]={1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5};
    int n = sizeof(arr)/sizeof(arr[0]); 
    int k = remove_duplicates(arr,n);
    cout << "The array after removing duplicates is: ";

    for(int i=0;i<k;i++)
        cout << arr[i] << " ";
}
