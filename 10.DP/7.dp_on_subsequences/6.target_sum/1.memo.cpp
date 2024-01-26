//solution works only for target>=0
#include<iostream>
#include<cstring>
#include<vector>
#include<numeric>
using namespace std;
#define mod int(1e9+7);
static int dp[21][1001];

int solve(vector<int>&arr,int i,int tar,int sum){
    if(i==0){
        if(sum==tar&&sum-2*arr[i]==tar){
            return 2;
        }
        if(sum==tar){
            return 1;
        }
        if (sum-2*arr[i]==tar){
            return 1;
        }
        return 0;
    }
    if (dp[i][sum]!=-1){
        return dp[i][sum];
    }
    int taken=0;
    int notTaken=solve(arr,i-1,tar,sum);
    if (tar<=sum-2*arr[i]){
        taken=solve(arr,i-1,tar,sum-2*arr[i]);
    }
    return dp[i][sum]=(taken+notTaken)%mod;
}
int main(){
    vector<int>arr={0,0,0,0,0,0,0,0,1};
    int n=arr.size();
    int target=1;
    int sum=accumulate(arr.begin(),arr.end(),0);
    memset(dp,-1,sizeof(dp));
    int result=solve(arr,n-1,target,sum);
    cout<<result;
}