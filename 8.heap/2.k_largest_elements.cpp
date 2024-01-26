#include<bits/stdc++.h>
using namespace std;

priority_queue<int,vector<int>,greater<int>> solve(int arr[],int n,int k){
    int i=0;
    priority_queue<int,vector<int>,greater<int>>minHeap;
    while(i<n){
        minHeap.push(arr[i]);
        if (k<minHeap.size()){
            minHeap.pop();
        }
        i++;
    }
    return minHeap;
}
int main(){
    int arr[]={7,10,4,3,20,15};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;
    priority_queue<int,vector<int>,greater<int>> result=solve(arr,n,k);
    while (!result.empty()){
        cout<<result.top()<<" ";
        result.pop();
    }
}