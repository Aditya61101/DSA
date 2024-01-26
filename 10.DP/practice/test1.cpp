#include<bits/stdc++.h>
#define vii vector<vector<int>>
using namespace std;
int solve(vii grid, vii dp,int r,int c){
    if(r==0&&c==0) return grid[0][0];
    if(r<0|| c<0) return 1e9;
    if(dp[r][c]!=-1) return dp[r][c];
    int left = grid[r][c]+solve(grid,dp,r,c-1);
    int up = grid[r][c]+solve(grid,dp,r-1,c);
    return dp[r][c]=min(left,up);
}
int main(){
    int n,m;
    cin>>n>>m;
    vii dp(n,vector<int>(m,-1));
    vii grid(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    cout<<solve(grid,dp,n-1,m-1);
}