class Solution {
    int n;
    int solve(int i, string &s, vector<int>&dp){
        if(i==n) return dp[i]=1;
        if(dp[i]!=-1) return dp[i];
        int count=0;
        for(int j=i;j<i+2 && j<n;j++){
            count+=solve(j+1,s,dp);
        }
        dp[i]=count;
    }
public:
    int numDecodings(string s) {
        n=s.length();
        vector<int>dp(n+1,-1);
        return solve(0,s,dp);
    }
}  