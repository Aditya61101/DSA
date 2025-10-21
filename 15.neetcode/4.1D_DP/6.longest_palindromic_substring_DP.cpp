#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        string ans="";
        vector<vector<bool>>dp(n, vector<bool>(n,false));
        for(int j=0;j<n;j++) {
            for(int i=0;i<=j;i++){
                if(s[i]==s[j] && ((j-i)<=2 || dp[i+1][j-1])) {
                    dp[i][j]=true;
                    ans = (j-i+1 > ans.length()) ? s.substr(i,j-i+1): ans;
                }
            }
        }
        return ans;
    }
};