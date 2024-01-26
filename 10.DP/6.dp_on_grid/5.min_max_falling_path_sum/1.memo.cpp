#include<iostream>
#include<climits>
#include<cstring>
using namespace std;

static int dp[100][100];
int solve(int i,int j,int c,int arr[4][4]){
    if (j<0||j>=c){
        return -1e9;
    }
    if (i==0){
        return arr[0][j];
    }
    if (dp[i][j]!=-1){
        return dp[i][j];
    }
    int up=arr[i][j]+solve(i-1,j,c,arr);
    int diagLeft=arr[i][j]+solve(i-1,j-1,c,arr);
    int diagRight=arr[i][j]+solve(i-1,j+1,c,arr);
    return dp[i][j]= max(up,max(diagLeft,diagRight));
}
int main(){
    int r,c;
    r=4,c=4;
    int arr[4][4]={{1,2,10,4},{100,3,2,1},{1,1,20,2},{1,2,2,1}};
    memset(dp,-1,sizeof(dp));
    int maxVal=-1e8;
    for (int j=0;j<c;j++){
        maxVal=max(maxVal,solve(r-1,j,c,arr));
    }
    cout<<maxVal;
}