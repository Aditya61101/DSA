class Solution {
    int solve(int step, int n, vector<int>&dp){
        if(step==n) return dp[step]=1;
        if(dp[step]!=-1) return dp[step];

        int count=0;
        for(int st:{1,2}){
            if(step+st<=n){
                count+=solve(step+st, n, dp);
            }
        }
        return dp[step]=count;
    }
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return solve(0,n,dp);
    }
};