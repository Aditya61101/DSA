#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        int max_s=INT_MIN;
        for(auto &st:wordDict) max_s=max(max_s,(int)st.length());
        unordered_set<string>wo(wordDict.begin(), wordDict.end());
        vector<bool>dp(n+1,false);
        dp[n]=true;
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n && j<=max_s+i-1;j++){
                string st=s.substr(i,j-i+1);
                if(wo.count(st)&&dp[j+1]){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[0];
    }
};