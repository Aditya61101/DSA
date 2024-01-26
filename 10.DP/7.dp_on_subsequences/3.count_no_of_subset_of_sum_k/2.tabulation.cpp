#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>arr={1,2,3,4};
    int k=4;
    int n=arr.size();
    vector<vector<int>>dp(n,vector<int>(k+1,0));
    for (int i=0; i<n; i++){
        dp[i][0]=1;
    }
    if (arr[0]<=k){
        dp[0][arr[0]]=1;
    }
    for (int i=1; i<n; i++){
        for (int sum=1; sum<k+1; sum++){
            int taken=0;
            if (sum>=arr[i]){
                taken=dp[i-1][sum-arr[i]];
            }
            int notTaken=dp[i-1][sum];
            dp[i][sum]=taken+notTaken;
        }
    }
    cout<<dp[n-1][k];
}