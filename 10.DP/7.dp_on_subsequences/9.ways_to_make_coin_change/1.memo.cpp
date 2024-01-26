#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int>&ip,int i,int tar,vector<vector<int>>dp){
    if(tar==0){
        return 1;
    }
    if(i==0){
        if (tar%ip[0]==0){
            return 1;
        }
        return 0;
    }
    if (dp[i][tar]!=-1){
        return dp[i][tar];
    }
    int notTake=solve(ip,i-1,tar,dp);
    int take=0;
    if(tar>=ip[i]){
        take=solve(ip,i,tar-ip[i],dp);
    }
    return dp[i][tar]=take+notTake;
}
int main(){
    vector<int>ip={1,2,3};
    int target=4;
    int n=ip.size();
    vector<vector<int>>dp(n,vector<int>(target+1,-1));
    int result=solve(ip,n-1,target,dp);
    cout<<result;
}