#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solve(string &s1,string &s2,int i,int j,vector<vector<int>>&dp){
    if (i<0||j<0){
        return 0;
    }
    if (dp[i][j]!=-1){
        return dp[i][j];
    }
    if (s1[i]==s2[j]){
        return dp[i][j]=1+solve(s1,s2,i-1,j-1,dp);
    }
    int notMatchMoveI=solve(s1,s2,i-1,j,dp);
    int notMatchMoveJ=solve(s1,s2,i,j-1,dp);
    return dp[i][j]=max(notMatchMoveI,notMatchMoveJ);
}
int main(){
    string s1="abcaa";
    string s2=s1;
    int n1=s1.length();
    reverse(s2.begin(),s2.end());
    int n2=s2.length();
    vector<vector<int>>dp(n1,vector<int>(n2,-1));
    int result=solve(s1,s2,n1-1,n2-1,dp);
    cout<<n1-result;
}
//the idea is to store a reversed string of the original string and find the longest common subsequence