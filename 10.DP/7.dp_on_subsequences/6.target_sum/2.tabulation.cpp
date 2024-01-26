#include<iostream>
#include<numeric>
#include<vector>
using namespace std;

int mod=(int)(1e9+7);
int main(){
    vector<int>arr={1};
    int n=arr.size();
    int totalSum=accumulate(arr.begin(),arr.end(),0);
    int target=1;
    vector<vector<int>>dp(n,vector<int>(target+1,0));
    for (int i=0;i<n;i++){
        dp[i][0]=1;
    }
    dp[0][totalSum-2*arr[0]]=1;
    for (int i=1;i<n;i++){
        for (int tar=1;tar<target+1; tar++){
            int taken=0;
            int notTaken=dp[i-1][tar];
            if (tar<=totalSum-2*arr[i]){
                taken=dp[i-1][totalSum-2*arr[i]-tar];
            }
            dp[i][tar]=(taken+notTaken);
        }
    }
    cout<<dp[n-1][target];
}