class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int>house(1e4+1);
        int n=house.size();
        for(int num:nums) house[num]+=num;
        vector<int>dp(n+1,0);
        dp[n-1]=house[n-1];
        for(int i=n-2;i>=0;i--){
            int take=0;
            take=house[i]+dp[i+2];
            int not_take=dp[i+1];
            dp[i]=max(take, not_take);
        }
        return dp[0];
    }
};
//TC:O(n), SC:O(n)