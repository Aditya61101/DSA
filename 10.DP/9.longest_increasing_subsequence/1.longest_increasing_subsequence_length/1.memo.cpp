#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int solve(vector<int>&v,int i,int prevI,vector<vector<int>>&dp){
    if (i==v.size()){
        return 0;
    }
    if (dp[i][prevI+1]!=-1){
        return dp[i][prevI+1];
    }
    int take=0;
    if (prevI==-1||v[i]>v[prevI]){
        take=1+solve(v,i+1,i,dp);
    }
    int notTake=solve(v,i+1,prevI,dp);
    return dp[i][prevI+1]=max(take,notTake);
}
int main(){
    vector<int>ip={10,9,2,5,3,7,18,101};
    int n=ip.size();
    vector<vector<int>>dp(n,vector<int>(n+1,-1));
    int result=solve(ip,0,-1,dp);
    cout<<result;
}