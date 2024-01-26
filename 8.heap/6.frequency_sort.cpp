#include<bits/stdc++.h>
using namespace std;

vector<int> solve(int arr[],int n){
    priority_queue<pair<int,int>>maxHeap;
    unordered_map<int,int>freq;
    vector<int>sorted;
    int i=0;
    while (i<n){
        freq[arr[i]]++;
        i++;
    }
    for (auto it:freq){
        maxHeap.push({it.second,it.first});
    }
    int count=0;
    while (!maxHeap.empty()){
        sorted.push_back(maxHeap.top().second);
        count++;
        if(count==maxHeap.top().first){
            count=0;
            maxHeap.pop();
        }
    }
    return sorted;
}
int main(){
    int arr[]={1,1,1,3,2,2,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>result=solve(arr,n);
     for (auto it:result){
        cout<<it<<" ";
    }
}