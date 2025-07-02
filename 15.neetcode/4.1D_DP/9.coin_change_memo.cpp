class Solution {
    int solve(int amount, vector<int>&coins, vector<int>&dp) {
        if(amount==0) return dp[amount]=0; // valid path, since no amount left we dont need to use any coin so we return 0
        if(dp[amount]!=-1) return dp[amount]; // already calculated min coins for this remaining amount so we don't need to do recursion
        
        int count=INT_MAX;
        for(int coin:coins){
            if(amount<coin) continue;
            int res=solve(amount-coin, coins, dp);
            if(res!=INT_MAX) count=min(count, 1+res);
        }
        return dp[amount]=count;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1, -1);
        int res=solve(amount, coins, dp);
        return res==INT_MAX? -1:res;
    }
};