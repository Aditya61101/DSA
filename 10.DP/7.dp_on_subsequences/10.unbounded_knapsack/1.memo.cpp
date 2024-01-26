#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int>&weight,vector<int>&price,int i,int W,vector<vector<int>>dp){
    if(i==0){
        if (weight[0]<=W){
            return (price[0]*(W/weight[0]));
        }
        return -1e9;
    }
    if (dp[i][W]!=-1){
        return dp[i][W];
    }
    int notTake=solve(weight,price,i-1,W,dp);
    int take=-1e9;
    if (weight[i]<=W){
        take=price[i]+solve(weight,price,i,W-weight[i],dp);
    }
    return dp[i][W]=max(take,notTake);
}
int main(){
    vector<int>weight={2,4,6};
    vector<int>price={5,11,13};
    int n=price.size();
    int W=10;
    vector<vector<int>>dp(n,vector<int>(W+1,-1));
    int result=solve(weight,price,n-1,W,dp);
    cout<<result;
}