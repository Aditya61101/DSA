#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int>&ip,int i,int n,vector<vector<int>>dp){
    if(i==0){
        return n*ip[0];
    }
    if (dp[i][n]!=-1){
        return dp[i][n];
    }
    int take=-1e9;
    int rodLength=i+1;
    if(rodLength<=n){
        take=ip[i]+solve(ip,i,n-rodLength,dp);
    }
    int notTake=solve(ip,i-1,n,dp);
    return dp[i][n]=max(take,notTake);
}
int main(){
    vector<int>ip={2,5,7,8,10};
    int n=ip.size();
    vector<vector<int>>dp(n,vector<int>(n+1,-1));
    int result=solve(ip,n-1,n,dp);
    cout<<result;
}