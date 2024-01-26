#include<bits/stdc++.h>
using namespace std;

int solve(int arr[],int n){
    int i=0,cost=0;
    priority_queue<int,vector<int>,greater<int>>minHeap;
    while (i<n){
        minHeap.push(arr[i]);
        i++;
    }
    while (minHeap.size()>=2){
        int first=minHeap.top();
        minHeap.pop();
        int second=minHeap.top();
        minHeap.pop();
        cost+=first+second;
        minHeap.push(first+second);
    }
    return cost;
}
int main(){
    int arr[]={3,1,2,5,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    int result=solve(arr,n);
}
//at anytime we need the smallest ropes/numbers, to get the minimum cost.