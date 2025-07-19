#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>freq;
        ranges::sort(nums);
        for(int num:nums) freq[num]++;
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            auto it=upper_bound(nums.begin(),nums.end(),nums[i]+1); // value bigger than nums[i]+1
            int idx=it-nums.begin(); // index of that value in nums array
            // multiples occurrence of nums[i] to take it at one go
            int take=freq[nums[i]]*nums[i]+dp[idx]; 
            int not_take=dp[i+1];
            dp[i]=max(take,not_take);
        }
        return dp[0];
    }
};
//TC:O(n*logn), SC:O(n)