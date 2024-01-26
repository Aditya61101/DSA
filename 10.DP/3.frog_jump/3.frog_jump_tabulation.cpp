#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int solve(int i,vector<int>&arr,vector<int>&dp){
    dp[0]=0;
    for (int s = 1; s < i+1 ; s++){
        int climb1=dp[s-1]+abs(arr[s-1]-arr[s]);
        int climb2=INT_MAX;
        if (s>1){
            climb2=dp[s-2]+abs(arr[s-2]-arr[s]);
        }
        dp[s]=min(climb1,climb2);
    }
    return dp[i];
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
    vector<int>dp(n+1);
    int result=solve(n-1,arr,dp);
    cout<<result;
}
//sum up the additional tasks.