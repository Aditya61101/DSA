#include<bits/stdc++.h>
using namespace std;
class Solution {
    int minimumTotal(vector<vector<int>>& triangle) {
        int r = triangle.size();
        int c = triangle[r-1].size();
        vector<vector<int>> dp(r+1, vector<int>(r+1, 0));

        for(int i=r-1;i>=0;i--){
            int r_size=triangle[i].size();
            for(int j=r_size-1;j>=0;j--){
                dp[i][j]=triangle[i][j]+min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};