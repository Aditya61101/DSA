#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&v,int k){
    priority_queue<int,vector<int>,greater<int>>minHeap;
    int i=0,n=v.size();
    while(i<n){
        minHeap.push(v[i]);
        if(minHeap.size()>k){
          minHeap.pop();  
        }
        i++;
    }
    //for kth largest element
    cout<<minHeap.top()<<"\n";
    //for k largest elements
    while(!minHeap.empty()){
        cout<<minHeap.top()<<" ";
        minHeap.pop();
    }
}
int main(){
    vector<int>v={1,5,3,12,0,7,14};
    int k=3;
    solve(v,k);
}