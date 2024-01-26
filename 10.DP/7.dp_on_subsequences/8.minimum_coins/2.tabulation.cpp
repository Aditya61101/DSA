#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>arr={1,2,3};
    int n=arr.size();
    int target=7;
    vector<vector<int>>dp(n,vector<int>(target+1,0));
    for (int tar=0; tar<target+1; tar++){
        if(tar%arr[0]==0){
            dp[0][tar]=tar/arr[0];
        }
        else{
            dp[0][tar]=1e9;
        }
    }
    for (int i=1; i<n; i++){
        for (int tar=0; tar<target+1; tar++){
            int take=1e9;
            if(0<=tar-arr[i]){
                take=1+dp[i][tar-arr[i]];
            }
            int notTake=dp[i-1][tar];
            dp[i][tar]=min(take,notTake);
        }
    }
    cout<<dp[n-1][target];
}