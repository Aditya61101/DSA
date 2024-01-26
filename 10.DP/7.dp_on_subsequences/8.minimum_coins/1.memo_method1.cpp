#include<iostream>
#include<vector>
using namespace std;

int solve(int i,vector<int>&arr,int target,int count,vector<vector<int>>dp){
    if(target==0){
        return count;
    }
    if (i==0){
        if(target-arr[0]==0){
            return count+1;
        }
        return 1e9;
    }
    if (dp[i][target]!=-1){
        return dp[i][target];
    }
    int take=1e9;
    if(0<=target-arr[i]){
        take=solve(i,arr,target-arr[i],count+1,dp);
    }
    int notTake=solve(i-1,arr,target,count,dp);
    return dp[i][target]=min(take,notTake);
}
int main(){
    vector<int>arr={1,2,3};
    int n=arr.size();
    int target=7;
    vector<vector<int>>dp(n,vector<int>(target+1,-1));
    int result=solve(n-1,arr,target,0,dp);
    cout<<result;
}
//multiple use or infinite supply, take=at same index.