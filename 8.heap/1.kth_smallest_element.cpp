#include<bits/stdc++.h>
using namespace std;

int solve(int arr[],int n,int k){
    int i=0;
    priority_queue<int>maxHeap;
    while(i<n){
        maxHeap.push(arr[i]);
        if (k<maxHeap.size()){
            maxHeap.pop();
        }
        i++;
    }
    return maxHeap.top();
}
int main(){
    int arr[]={7,10,4,3,20,15};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;
    int result=solve(arr,n,k);
    cout<<result;
}