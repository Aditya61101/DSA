class Solution {
    int solve(int i, int n, vector<int>&nums, vector<int>&dp) {
        if(i==n-1) return dp[i]=nums[i];
        if(i==n) return dp[i]=0;
        if(dp[i]!=-1) return dp[i];
        
        int rob = nums[i]+solve(i+2, n, nums, dp);
        int dont_rob = solve(i+1, n, nums, dp);
        return dp[i]=max(rob, dont_rob);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        vector<int>dp1(n+1, -1);
        int with_last = solve(1,n,nums,dp1);
        vector<int>dp2(n+1, -1);
        int with_first = solve(0,n-1,nums,dp2);
        return max(with_first, with_last);
    }
};