#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int maxLen=1;
        vector<int>dp(n+1,0);
        // trying LIS from every starting index
        for(int i=n-1;i>=0;i--){
            dp[i]=1;
            for(int j=i+1;j<n;j++){
                // for strict increasing order, jth one has to be strictly greater than ith one
                if(nums[j]>nums[i]) dp[i]=max(dp[i],1+dp[j]);
            }
            maxLen=max(maxLen, dp[i]);
        }
        return maxLen;
    }
};