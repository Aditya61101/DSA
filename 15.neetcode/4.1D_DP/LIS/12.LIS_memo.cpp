#include<bits/stdc++.h>
using namespace std;
class Solution {
    int n;
    int solve(int i, vector<int>&nums, vector<int>&dp) {
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int len=1;
        for(int j=i+1;j<n;j++){
            // for strict increasing order, jth one has to be strictly greater than ith one
            if(nums[j]>nums[i]){
                len=max(len, 1+solve(j, nums, dp));
            }
        }
        return dp[i]=len;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        int maxLen=1;
        vector<int>dp(n,-1);
        // trying LIS from every starting index
        for(int i=0;i<n;i++){
            maxLen=max(maxLen, solve(i,nums, dp));
        }
        return maxLen;
    }
};