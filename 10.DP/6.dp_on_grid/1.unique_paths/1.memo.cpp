#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

static int dp[100][100];
int solve(int r,int c){
    if (r==0&&c==0){
        return 1;
    }
    if (r<0||c<0){
        return 0;
    }
    if (dp[r][c]!=-1){
        return dp[r][c];
    }
    int alongRow=solve(r-1,c);
    int alongColumn=solve(r,c-1);
    return dp[r][c]=alongRow+alongColumn;
}
int main(){
    int r,c;
    cin>>r>>c;
    memset(dp,-1,sizeof(dp));
    int result=solve(r-1,c-1);
    cout<<result;
}