#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

int mod=(int)(1e9+7);
int main(){
    vector<int>arr={5,2,6,4};
    int d=3;
    int sum=accumulate(arr.begin(),arr.end(),0);
    int k=(sum+d)/2;
    if (k%2!=0){
        cout<<0;
        return 0;
    }
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
            dp[i][sum]=(taken+notTaken)%mod;
        }
    }
    cout<<dp[n-1][k];
}