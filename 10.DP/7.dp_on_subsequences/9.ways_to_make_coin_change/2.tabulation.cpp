#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>ip={1,2,3};
    int target=4;
    int n=ip.size();
    vector<vector<int>>dp(n,vector<int>(target+1,0));
    for (int tar=0; tar<=target; tar++){
        if (tar%ip[0]==0){
            dp[0][tar]=1;
        }
        else{
            dp[0][tar]=0;
        }
    }
    for (int i=1; i<n; i++){
        for (int tar=0; tar<target+1; tar++){
            int notTake=dp[i-1][tar];
            int take=0;
            if(tar>=ip[i]){
                take=dp[i][tar-ip[i]];
            }
            dp[i][tar]=take+notTake;
        }
    }
    cout<<dp[n-1][target];
}