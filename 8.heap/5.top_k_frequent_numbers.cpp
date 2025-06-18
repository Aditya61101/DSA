#include<bits/stdc++.h>
#include<unordered_map>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<int,int> p;

void solve(int arr[],int n,int k){
    priority_queue<p,vector<p>,greater<p>>minHeap;
    unordered_map<int,int>freq;
    int i=0;
    while(i<n){
        freq[arr[i]]++;
        i++;
    }
    for(auto it:freq){
        minHeap.push({it.second,it.first});
        if (k<minHeap.size()){
            minHeap.pop();
        }
    }
    while (!minHeap.empty()){
        cout<<minHeap.top().second<<" ";
        minHeap.pop();
    }
}
int main(){
    int arr[]={1,2,2,3,3,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=2;
    solve(arr,n,k);
}