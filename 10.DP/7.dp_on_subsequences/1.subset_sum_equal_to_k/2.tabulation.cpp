#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>arr={1,2,3,4};
    int k=4;
    int n=arr.size();
    vector<vector<bool>>dp(n,vector<bool>(k+1,false));
    for (int i=0; i<n; i++){
        dp[i][0]=true;
    }
    if (arr[0]<=k){
        dp[0][arr[0]]=true;
    }
    for (int i=1; i<n; i++){
        for (int sum=1; sum<k+1; sum++){
            bool taken=false;
            if (sum>=arr[i]){
                taken=dp[i-1][sum-arr[i]];
            }
            bool notTaken=dp[i-1][sum];
            dp[i][sum]=taken|notTaken;
        }
    }
    cout<<dp[n-1][k];
}