#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

static int dp[1000][1000];
int solve(vector<int>&weight,vector<int>&money,int W,int i){
    if(i==0){
        if (W-weight[0]>=0){
            return money[0];
        }
        return 0;
    }
    if(dp[i][W]!=-1){
        return dp[i][W];
    }
    int notTake=solve(weight,money,W,i-1);
    int take=-1e9;
    if(W-weight[i]>=0){
        take=money[i]+solve(weight,money,W-weight[i],i-1);
    }
    return dp[i][W]=max(take,notTake);
}
int main(){
    vector<int>weight={3,4,5};
    vector<int>money={30,50,60};
    int W=8;
    int n=weight.size();
    memset(dp,-1,sizeof(dp));
    int result=solve(weight,money,W,n-1);
    cout<<result;
}