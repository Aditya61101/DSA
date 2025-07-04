class Solution {
    int solve(int n, vector<int>&dp){
        if(n==0||n==1||n==2) return dp[n]=n==2?1:n;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=solve(n-1,dp)+solve(n-2,dp)+solve(n-3,dp);
    }
public:
    int tribonacci(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};