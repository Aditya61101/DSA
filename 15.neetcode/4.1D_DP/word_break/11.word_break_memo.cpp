#include<bits/stdc++.h>
using namespace std;
class Solution {
    int n, max_s;
    bool solve(int i, string &s, unordered_set<string>&wo, vector<int>&dp) {
        if(i==n) return true;
        if(dp[i]!=-1) return dp[i];
        for(int j=i;j<n && j<=max_s+i-1;j++){
            string st=s.substr(i,j-i+1);
            if(wo.count(st)&&solve(j+1,s,wo,dp)) return true;
        }
        return dp[i]=false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        n=s.length();
        max_s=INT_MIN;
        for(auto &st:wordDict) max_s=max(max_s, (int)st.length());
        unordered_set<string>word_set(wordDict.begin(), wordDict.end());
        vector<int>dp(n,-1);
        return solve(0,s,word_set, dp);
    }
};