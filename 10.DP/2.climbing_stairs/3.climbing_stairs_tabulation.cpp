#include<iostream>
#include<vector>
using namespace std;
#define lli long long int

int solve(int n,vector<int>&dp){
    dp[0]=1;
    for (int i = 1; i < n+1; i++){
        int climb1=dp[i-1];
        int climb2=0;
        if(i>=2){
            climb2=dp[i-2];
        }
        dp[i]=climb1+climb2;
    }
    return dp[n];
}
int main(){
    lli n;
    cin>>n;
    vector<int>dp(n+1);
    int result=solve(n,dp);
    cout<<result;
}