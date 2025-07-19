#include<bits/stdc++.h>
using namespace std;
class Solution {
    int minimumTotal(vector<vector<int>>& triangle) {
        int r = triangle.size();
        int c = triangle[r-1].size();
        vector<int>dp(triangle.back());

        for(int i=r-1;i>=0;i--){
            int r_size=triangle[i].size();
            for(int j=0;j<r_size;j++){
                dp[j]=triangle[i][j]+min(dp[j],dp[j+1]);
            }
        }
        return dp[0];
    }
};