#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    int solve(int i, vector<int>&house, vector<int>&dp) {
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int take = house[i]+solve(i+2,house,dp);
        int not_take = solve(i+1,house,dp);
        return dp[i]=max(take, not_take);
    }
    int deleteAndEarn(vector<int>& nums) {
        vector<int>house(1e4+1); // constraint: nums[i]<=1e4
        n=house.size();
        for(int num:nums) house[num]+=num;
        vector<int>dp(n,-1);
        return solve(0,house,dp);
    }
};