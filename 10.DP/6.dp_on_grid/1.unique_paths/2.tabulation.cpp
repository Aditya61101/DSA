#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

static int dp[100][100];
int solve(int r,int c){
    dp[0][0]=1;
    for (int i=0; i<r+1; i++){
        for (int j=0; j<c+1; j++){
            if (i==0&&j==0){
                continue;
            }
            int alongRow=0,alongColumn=0;
            if (i>0){
                alongRow=dp[i-1][j];
            }
            if (j>0){
                alongColumn=dp[i][j-1];   
            }
            dp[i][j]=alongRow+alongColumn;
        }
    }
    return dp[r][c];
}
int main(){
    int r,c;
    cin>>r>>c;
    int result=solve(r-1,c-1);
    cout<<result;
}