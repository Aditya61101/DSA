#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
static int dp[1000][1000];

int solve(vector<int>&arr,int i,int sum){ 
    if (i==0){
        if (sum==0&&arr[0]==0){
            return 2;
        }
        if (sum==0||sum==arr[0]){
            return 1;
        }
        return 0;
    }
    if (dp[i][sum]!=-1){
        return dp[i][sum];
    }
    int taken=0;
    if (sum>=arr[i]){
        taken=solve(arr,i-1,sum-arr[i]);
    }
    int notTaken=solve(arr,i-1,sum);
    return dp[i][sum]=taken+notTaken;
}
int main(){
    vector<int>arr={1,2,2,3};
    int k=3;
    int n=arr.size();
    memset(dp,-1,sizeof(dp));
    int result=solve(arr,n-1,k);
    cout<<result;
}
//if the array consists of a 0s. then no. of subsets will be pow(2,n)*sum.