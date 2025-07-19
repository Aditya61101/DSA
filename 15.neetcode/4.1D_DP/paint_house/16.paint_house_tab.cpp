#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>dp;
int solve(vector<vector<int>> &A) {
    int n=A.size();
    dp.resize(n+1,vector<int>(3,INT_MAX));
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<3;j++){
            dp[i][j]=A[i][j]+min(dp[i+1][(j+1)%3],dp[i+1][(j+2)%3]);
        }
    }
    return min({dp[0][0],dp[0][1],dp[0][2]});
}
//TC:O(n), SC:O(3*n)
