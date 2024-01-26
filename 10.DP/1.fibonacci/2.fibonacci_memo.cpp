#include<iostream>
#include<vector>
using namespace std;

int solve(int n,vector<int>&dp){
    if(n==0||n==1)
        return dp[n]=n;
    if(dp[n]!=-1)
        return dp[n];
    return dp[n]=solve(n-1,dp)+solve(n-2,dp);
}
int main(){
    int n;
    cin>>n;
    vector<int>dp(n+1,-1);
    int result = solve(n,dp);
    cout<<result;
}
//T.C: O(N)
//S.C: O(N)+O(N)