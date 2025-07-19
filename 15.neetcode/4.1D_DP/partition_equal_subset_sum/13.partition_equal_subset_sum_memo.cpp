#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    bool solve(int i, int tar, vector<int>& nums, vector<vector<int>>& dp) {
        if (tar==0) return true;
        if (i==n) return false;
        if (dp[i][tar] != -1) return dp[i][tar];

        bool take = false;
        if (nums[i] <= tar) take = solve(i+1, tar-nums[i], nums, dp);
        bool notTake = solve(i+1, tar, nums, dp);

        return dp[i][tar] = take||notTake;
    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(), nums.end(), 0);
        if(sum%2!=0) return false;
        int tar=sum/2;
        n=nums.size();
        vector<vector<int>>dp(n,vector<int>(tar+1,-1));
        return solve(0,tar,nums,dp);
    }
};
//TC: O(n*tar), SC:O(n*tar)