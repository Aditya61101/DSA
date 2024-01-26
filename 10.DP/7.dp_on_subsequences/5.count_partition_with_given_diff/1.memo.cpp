#include<iostream>
#include<vector>
#include<cstring>
#include<numeric>
using namespace std;

static int dp[1000][1000];
int mod=(int)(1e9+7);
int solve(vector<int>&arr,int i,int sum){
    if (sum==0){
        return 1;
    }
    if (i==0){
        return (arr[0]==sum);
    }
    if (dp[i][sum]!=-1){
        return dp[i][sum];
    }
    int taken=0;
    int notTaken=solve(arr,i-1,sum);
    if (arr[i]<=sum){
        taken=solve(arr,i-1,sum-arr[i]);
    }
    return dp[i][sum]=(taken+notTaken)%mod;
}
int main(){
    vector<int>arr={5,2,6,4};
    int d=3;
    int n=arr.size();
    int sum=accumulate(arr.begin(),arr.end(),0);
    int k=(d+sum)/2;
    if (k%2!=0){
        cout<<0;
        return 0;
    }
    memset(dp,-1,sizeof(dp));
    int result=solve(arr,n-1,k);
    cout<<result;
}