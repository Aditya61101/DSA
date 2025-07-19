#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>>dp;
int func(int i, int j, vector<vector<int>>&A){
    if(i==n) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j]=A[i][j]+min(func(i+1,(j+1)%3,A), func(i+1,(j+2)%3,A));
}

int solve(vector<vector<int>> &A) {
    n=A.size();
    dp.resize(n,vector<int>(3,-1));
    return min({func(0,0,A), func(0,1,A), func(0,2,A)});
}
//TC:O(n), SC:O(3*n)