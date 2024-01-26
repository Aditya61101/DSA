#include<bits/stdc++.h>
using namespace std;

vector<int> solve(int arr[],int n,int k){
    int i=0;
    vector<int>sorted;
    priority_queue<int,vector<int>,greater<int>>minHeap;
    while(i<n){
        minHeap.push(arr[i]);
        if (k<minHeap.size()){
            sorted.push_back(minHeap.top());
            minHeap.pop();
        }
        i++;
    }
    while (!minHeap.empty()){
        sorted.push_back(minHeap.top());
        minHeap.pop();
    }
    return sorted;
}
int main(){
    int arr[]={6,5,3,2,8,10,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;
    vector<int>result=solve(arr,n,k);
    for(auto &e:result){
        cout<<e<<" ";
    }
}
//k sorted array means that the element present in the fully sorted array will present at most k to the left or to the right in the given array.