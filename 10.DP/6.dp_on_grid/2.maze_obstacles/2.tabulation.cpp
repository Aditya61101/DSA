#include<iostream>
#include<cstring>
using namespace std;

static int dp[100][100];
int solve(int i,int j,int arr[][3]){
    dp[0][0]=1;
    for (int in = 0; in < i+1; in++){
        for (int jn = 0; jn < j+1; jn++){
            int alongRow=0,alongColumn=0;
            if (in==0&&jn==0){
                continue;
            }
            if (in>0&&arr[in-1][jn]!=-1){
                alongRow=dp[in-1][jn];
            }
            if (jn>0&&arr[in][jn-1]!=-1){
                alongColumn=dp[in][jn-1];
            }
            dp[in][jn]=alongRow+alongColumn;
        }
    }
    return dp[i][j];
}
int main(){
    int r,c;
    int arr[3][3]={{0,0,0},{0,-1,0},{0,0,0}};
    memset(dp,-1,sizeof(dp));
    int result=solve(2,2,arr);
    cout<<result;
}