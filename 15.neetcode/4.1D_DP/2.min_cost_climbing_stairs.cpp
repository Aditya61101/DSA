class Solution {
    int solve(int i, int n, vector<int>&dp, vector<int>&cost){
        if(i==n) return dp[i]=0;
        if(dp[i]!=-1) return dp[i];

        int minCost=INT_MAX; // level/local variable
        // below for loop traverses the level(choices) at a particular depth
        for(int di:{1,2}){
            if(i+di<=n){
                minCost=min(minCost, cost[i]+solve(i+di, n, dp, cost));
            }
        }
        return dp[i]=minCost;
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1, -1);
        int ans = min(solve(0,n,dp,cost), solve(1,n,dp,cost));
        for(auto d:dp) cout<<d<<" ";
        return ans;
    }
};