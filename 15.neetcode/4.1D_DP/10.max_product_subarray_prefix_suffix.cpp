class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxVal=INT_MIN, prefix=1, suffix=1;
        for(int i=0;i<n;i++) {
            prefix*=nums[i];
            suffix*=nums[n-i-1];
            maxVal=max({maxVal, prefix, suffix});
            if(prefix==0) prefix=1;
            if(suffix==0) suffix=1;
        }
        return maxVal;
    }
};