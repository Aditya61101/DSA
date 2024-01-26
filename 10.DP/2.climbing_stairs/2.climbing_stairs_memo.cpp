#include<iostream>
#include<vector>
using namespace std;
#define lli long long int

int solve(lli n,vector<int>&dp){
    if(n==0)
        return 1;

    if(dp[n]!=-1)
        return dp[n];

    int climb1=solve(n-1,dp);
    int climb2=0;
    if(n>=2)
        climb2=solve(n-2,dp);
    return dp[n]=climb1+climb2;
}
int main(){
    lli n;
    cin>>n;
    vector<int>dp(n+1,-1);
    int result=solve(n,dp);
    cout<<result;
}