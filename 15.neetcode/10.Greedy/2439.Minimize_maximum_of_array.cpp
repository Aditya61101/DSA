#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int sum=0,ans=0;
        for (int i=0;i<nums.size();i++){
            sum+=nums[i];
            int avg=(sum+i)/(i+1);
            ans=max(ans,avg);
        }
        return ans;
    }
};