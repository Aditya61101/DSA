class Solution {
    int n;
    bool isValid(string &s) {
        if(s[0]=='0') return false;
        int num=stoi(s);
        if(num>26) return false;
        return true;
    }
    int solve(int i, string &s, vector<int>&dp){
        if(i==n) return dp[i]=1;
        if(dp[i]!=-1) return dp[i];
        int count=0;
        for(int j=i;j<i+2 && j<n;j++){
            string st=s.substr(i,j-i+1);
            if(isValid(st)) count+=solve(j+1,s,dp);
        }
        dp[i]=count;
    }
public:
    int numDecodings(string s) {
        n=s.length();
        vector<int>dp(n+1,-1);
        dp[n]=1;
        for(int i=n-1;i>=0;i--){
            int count=0;
            for(int j=i;j<(i+2)&&j<n;j++){
                string st = s.substr(i,j-i+1);
                if(isValid(st)) count+=dp[j+1];
            }
            dp[i]=count;
        }
        return dp[0];
    }
}  