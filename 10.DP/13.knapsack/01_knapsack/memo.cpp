#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;

int solve(vector<vi> dp, vi wt, vi val, int W, int n){
    if(n==0||W==0)
        return 0;
    if(dp[n][W]!=-1)
        return dp[n][W];
    if(wt[n-1]<=W){
        int take = val[n-1]+solve(dp,wt,val,W-wt[n-1],n-1);
        int notTake = solve(dp,wt,val,W,n-1);
        return dp[n][W] = max(take,notTake);
    } else{
        return dp[n][W] = solve(dp,wt,val,W,n-1);
    }
}
int main(){
    vi wt = {1,3,4,5};
    vi val = {1,4,5,7};
    int n = wt.size();
    int W = 7;
    vector<vi>dp(n+1,vi(W+1,-1));
    cout<< solve(dp,wt,val,W,n);
}
//vector<vector<int>>(n,vector<int>(m,-1));