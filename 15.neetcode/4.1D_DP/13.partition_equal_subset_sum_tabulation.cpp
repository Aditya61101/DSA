class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(), nums.end(), 0);
        if(sum%2!=0) return false;

        int tar=sum/2;
        vector<vector<bool>>dp(n+1,vector<int>(tar+1,false));
        for(int i=0;i<=n;i++) dp[i][0]=true;

        for(int i=n-1;i>=0;i--){
            for(int t=tar;t>=0;t--){
                bool take = false;
                if(nums[i]<=t) take = dp[i+1][t-nums[i]];
                dp[i][t]=take||dp[i+1][t];
            }
        }
        return dp[0][tar];
    }
};
//TC: O(n*tar), SC:O(n*tar)