#include<bits/stdc++.h>
using namespace std;

int maxSum(vector<int>&arr,int k){
    int maxSum=INT_MIN,i=0,j=0;
    int sum=0,n=arr.size();
    while(j<n){
        sum+=arr[j];
        if(j-i+1==k){
            maxSum=max(sum,maxSum);
            sum-=arr[i];
            i++;
        }
        j++;
    }
    return maxSum;
}
int main(){
    vector<int>arr={2,5,1,8,2,9,1};
    int k=3;
    int sum = maxSum(arr,k);
    cout<<sum;
}