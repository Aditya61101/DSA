#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int>&v,int i,int j,vector<vector<int>>&dp){
    if (i>j){
        return 0;
    }
    if (dp[i][j]!=-1){
        return dp[i][j];
    }
    int maxCoins=-1e9;
    for (int k=i;k<=j;k++){
        int totalCoins=v[i-1]*v[k]*v[j+1]+solve(v,i,k-1,dp)+solve(v,k+1,j,dp);
        maxCoins=max(maxCoins,totalCoins);
    }
    return dp[i][j]=maxCoins;
}
int main(){
    vector<int>coins={3,1,5,8};
    int n=coins.size();
    coins.insert(coins.begin(),1);
    coins.push_back(1);
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    int result=solve(coins,1,n,dp);
    cout<<result;
}