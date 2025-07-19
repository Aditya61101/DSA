#include<bits/stdc++.h>
using namespace std;

int n;
vector<int>dp;
class Solution {
    int solve(int i,vector<int>&cost){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];

        dp[i]=INT_MAX;
        if(i+1<=n) dp[i]=min(dp[i],cost[i]+solve(i+1,cost));
        if(i+2<=n) dp[i]=min(dp[i],cost[i]+solve(i+2,cost));
        return dp[i];
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        n=cost.size();
        dp.resize(n,-1);
        int ans = min(solve(0,cost), solve(1,cost));
        return ans;
    }
};