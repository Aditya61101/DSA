#include<iostream>
#include<vector>
using namespace std;

int solve(int in,vector<int>&ip,vector<int>&dp){
    if (in==0){
        return ip[in];
    }
    if (in<0){
        return 0;
    }
    if (dp[in]!=-1){
        return dp[in];
    }
    int pick=ip[in]+solve(in-2,ip,dp);
    int notPick=solve(in-1,ip,dp);
    return dp[in]=max(pick,notPick);
}
int main(){
    vector<int>ip={2,1,4,9};
    vector<int>dp(ip.size()+1,-1);
    int result=solve(ip.size()-1,ip,dp);
    cout<<result;
}