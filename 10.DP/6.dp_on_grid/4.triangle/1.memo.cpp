#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

static int dp[100][100];
int solve(int i,int j,int r,int c,int arr[4][4]){
    if (i==r){
        return arr[i][j];
    }
    if (dp[i][j]!=-1){
        return dp[i][j];
    }
    int diag=arr[i][j]+solve(i+1,j+1,r,c,arr);
    int down=arr[i][j]+solve(i+1,j,r,c,arr);
    return dp[i][j]=min(diag,down);
}
int main(){
    int arr[4][4]={{1,0,0,0},{2,3,0,0},{3,6,7,0},{8,9,6,10}};
    int r=4,c=4;
    memset(dp,-1,sizeof(dp));
    int result=solve(0,0,r-1,c-1,arr);
    cout<<result;
}