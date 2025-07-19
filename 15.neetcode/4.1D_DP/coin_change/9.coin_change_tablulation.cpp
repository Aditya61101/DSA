#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,INT_MAX);
        dp[0]=0; // amount=0 means no coin needed
        for(int amt=1;amt<=amount;amt++){
            for(int coin:coins){
                if(amt<coin) continue;
                int res=dp[amt-coin];
                if(res!=INT_MAX) dp[amt]=min(dp[amt], 1+res);
            }
        }
        return dp[amount]==INT_MAX ? -1:dp[amount];
    }
};