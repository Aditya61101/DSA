#include<bits/stdc++.h>
using namespace std;
class Solution {
    int n;
    bool isValid(string &s) {
        if(s[0]=='0') return false;
        int num=stoi(s);
        if(num>26) return false;
        return true;
    }
public:
    int numDecodings(string s) {
        n=s.length();
        vector<int>dp(n+1,0);
        dp[n]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<(i+2)&&j<n;j++){
                string st = s.substr(i,j-i+1);
                if(isValid(st)) dp[i]+=dp[j+1];
            }
        }
        return dp[0];
    }
};