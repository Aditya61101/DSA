#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int solve(int i,vector<int>&arr,vector<int>&dp){
    if (i==0){
        return dp[i]=0;
    }
    if (dp[i]!=-1){
        return dp[i];
    }
    int climb1=solve(i-1,arr,dp)+abs(arr[i-1]-arr[i]);
    int climb2=INT_MAX;
    if (i>1){
        climb2=solve(i-2,arr,dp)+abs(arr[i-2]-arr[i]);
    }
    return dp[i]=min(climb1,climb2);
}
int main(){
    int n;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    vector<int>dp(n+1,-1);
    int result=solve(n-1,arr,dp);
    cout<<result;
}
//sum up the additional tasks.