//this method will work only for positive integers
#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>&arr,int k){
    long i=0,j=0,sum=0,maxSize=0,n=arr.size();
    while(j<n){
        sum+=arr[j];
        if(sum==k){
            maxSize=max(maxSize,j-i+1);
        }
        else if(sum>k){
            sum-=arr[i];
            i++;
        }
        j++;
    }
    return maxSize;
}
int main(){
    // int arr[] = {1,4,1,1,1,2,3,5};
    vector<int>arr={10,5,2,7,1,9};
    int k=15;
    int size=maxSubArray(arr,k);
   cout<<size;
}