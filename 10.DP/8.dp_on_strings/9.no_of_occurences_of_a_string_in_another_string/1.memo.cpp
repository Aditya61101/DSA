#include<iostream>
#include<vector>
using namespace std;

int solve(string &s1,string &s2,int i,int j,vector<vector<int>>&dp){
    if (j<0){
        return 1;
    }
    if (i<0){
        return 0;
    }
    if (dp[i][j]!=-1){
        return dp[i][j];
    }
    if (s1[i]==s2[j]){
        return dp[i][j]=solve(s1,s2,i-1,j-1,dp)+solve(s1,s2,i-1,j,dp);
    }
    return dp[i][j]=solve(s1,s2,i-1,j,dp);
}
int main(){
    string s1="babgbag";
    int n1=s1.length();
    string s2="bag";
    int n2=s2.length();
    vector<vector<int>>dp(n1,vector<int>(n2,-1));
    int result=solve(s1,s2,n1-1,n2-1,dp);
    cout<<result;
}
//if all characters of s2 matches it means that j<0 so, we should return 1;
//but if j>=0 and i<0 then all the char of s2 didn't match but the string s1 got exhausted.
//if chars matches then we can either move both the pointers(i-1,j-1) or we can search for another occurrence of that matched character(i-i,j).