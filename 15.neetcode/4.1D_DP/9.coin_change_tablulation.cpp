class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1, -1);
        dp[0]=0; // amount=0 means no coin needed
        for(int amt=1;amt<=amount;amt++){
            int count=INT_MAX;
            for(int coin:coins){
                if(amt<coin) continue;
                int res=dp[amt-coin];
                if(res!=INT_MAX) dp[amt]=min(count, 1+res);
            }
            dp[amt]=count;
        }
        return dp[amount]==INT_MAX ? -1:dp[amount];
    }
};