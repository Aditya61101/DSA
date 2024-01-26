#include<bits/stdc++.h>
using namespace std;

int smallestFinder(int arr[],int n,int k){
    int i=0;
    priority_queue<int>maxHeap;
    while (i<n){
        maxHeap.push(arr[i]);
        if (k<maxHeap.size()){
            maxHeap.pop();
        }
        i++;
    }
    return maxHeap.top();
}
int solve(int arr[],int n,int k1,int k2){
    int first=smallestFinder(arr,n,k1);
    int second=smallestFinder(arr,n,k2);
    int i=0,sum=0;
    while(i<n){
        if(arr[i]>first&&arr[i]<second){
            sum+=arr[i];
        }
        i++;
    }
    return sum;
}
int main(){
    int arr[]={1,3,12,5,15,11};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k1=3,k2=6;
    int result=solve(arr,n,k1,k2);
    cout<<result;
}