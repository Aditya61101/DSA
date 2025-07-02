class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxVal=nums[0], curr_max=nums[0], curr_min=nums[0];
        for(int i=1;i<n;i++) {
            int prev_min=curr_min, prev_max=curr_max;
            curr_max=max({nums[i], nums[i]*prev_max, nums[i]*prev_min});
            curr_min=min({nums[i], nums[i]*prev_max, nums[i]*prev_min});
            maxVal=max(maxVal, curr_max);
        }
        return maxVal;
    }
};