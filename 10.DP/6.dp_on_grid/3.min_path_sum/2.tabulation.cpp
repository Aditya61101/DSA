#include<iostream>
#include<climits>
#include<algorithm>
#include<cstring>
using namespace std;

static int dp[100][100];
int solve(int r,int c,int arr[][3]){
    dp[0][0]=arr[0][0];
    for (int i = 0; i < r+1; i++){
        for (int j = 0; j < c+1; j++){
            if (i==0&&j==0){
                continue;
            }
            int up=1e9,left=1e9;
            if (i>0){
                up=arr[i][j]+dp[i-1][j];
            }
            if (j>0){
                left=arr[i][j]+dp[i][j-1];
            }
            dp[i][j]=min(up,left);
        }
    }
    return dp[r][c];
}
int main(){
    int r,c;
    int arr[2][3]={{5,9,6},{11,5,2}};
    int result=solve(1,2,arr);
    cout<<result;
}
//if min is required and we are at unreachable place we return something which is biggest.