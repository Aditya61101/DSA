#include<bits/stdc++.h>
using namespace std;
class Solution {
    int solve(int step, int n, vector<int>&dp){
        if(step==n) return 1;
        if(dp[step]!=-1) return dp[step];

        int count=0;
        if(step+1<=n) count+=solve(step+1, n, dp);
        if(step+2<=n) count+=solve(step+2, n, dp);
        return dp[step]=count;
    }
public:
    int climbStairs(int n) {
        vector<int>dp(n,-1);
        return solve(0,n,dp);
    }
};