#include<bits/stdc++.h>
using namespace std;

void solve(int arr[],int n,int k,int x){
    int i=0;
    priority_queue<pair<int,int>>maxHeap;
    while (i<n){
        maxHeap.push({(abs(arr[i]-x)),arr[i]});
        if (k<maxHeap.size()){
            maxHeap.pop();
        }
        i++;
    }
    while (!maxHeap.empty()){
        cout<<maxHeap.top().second<<" ";
        maxHeap.pop();
    }
}
int main(){
    int arr[]={8,6,5,7,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;
    int x=10;
    solve(arr,n,k,x);
}