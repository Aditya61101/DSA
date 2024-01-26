#include<iostream>
#include<climits>
#include<algorithm>
#include<cstring>
using namespace std;

static int dp[100][100];
int solve(int r,int c,int arr[][3]){
    if (r==0&&c==0){
        return arr[0][0];
    }
    if (r<0||c<0){
        return 1e9;
    }
    if (dp[r][c]!=-1){
        return dp[r][c];
    }
    int up=arr[r][c]+solve(r-1,c,arr);
    int left=arr[r][c]+solve(r,c-1,arr);
    return dp[r][c]=min(up,left);
}
int main(){
    int r,c;
    // cin>>r>>c;
    int arr[2][3]={{5,9,6},{11,5,2}};
    memset(dp,-1,sizeof(dp));
    int result=solve(1,2,arr);
    cout<<result;
}
//if min is required and we are at unreachable place we return something which is biggest.