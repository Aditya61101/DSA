class Solution {
    int n;
    int solve(int i,vector<int>&nums, vector<int>&dp) {
        if(i==n-1) return dp[i]=nums[i];
        if(i==n) return dp[i]=0;
        if(dp[i]!=-1) return dp[i];
        
        int rob = nums[i]+solve(i+2, nums, dp);
        int dont_rob = solve(i+1, nums, dp);
        return dp[i]=max(rob, dont_rob);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,0);
        dp[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            dp[i]=max(dp[i+1], dp[i+2]+nums[i]);
        }
        return dp[0];
    }
};