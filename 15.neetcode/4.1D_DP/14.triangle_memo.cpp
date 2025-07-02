class Solution {
    int r, c;
    int solve(int i, int j, vector<vector<int>>& tri, vector<vector<int>>& dp) {
        if (i == r) return 0;
        if (i > r || j > c) return INT_MAX;
        if (dp[i][j] != -1) return dp[i][j];
        
        int same = tri[i][j] + solve(i + 1, j, tri, dp);
        int diff = tri[i][j] + solve(i + 1, j + 1, tri, dp);
        return dp[i][j] = min(same, diff);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        r = triangle.size();
        c = triangle[r-1].size();
        vector<vector<int>> dp(r+1, vector<int>(r+1, -1));

        return solve(0,0,triangle,dp);
    }
};