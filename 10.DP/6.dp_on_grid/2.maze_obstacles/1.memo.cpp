#include<iostream>
#include<cstring>
using namespace std;

static int dp[100][100];
int solve(int i,int j,int arr[][3]){
    if(i==0&&j==0){
        return 1;
    }
    if (i<0||j<0){
        return 0;
    }
    if (dp[i][j]!=-1){
        return dp[i][j];
    }
    int alongRow=0,alongColumn=0;
    if (arr[i-1][j]!=-1){
        alongRow=solve(i-1,j,arr);
    }
    if (arr[i][j-1]!=-1){
        alongColumn=solve(i,j-1,arr);
    }
    return dp[i][j]=alongRow+alongColumn;
}
int main(){
    int r,c;
    int arr[3][3]={{0,0,0},{0,-1,0},{0,0,0}};
    memset(dp,-1,sizeof(dp));
    int result=solve(2,2,arr);
    cout<<result;
}