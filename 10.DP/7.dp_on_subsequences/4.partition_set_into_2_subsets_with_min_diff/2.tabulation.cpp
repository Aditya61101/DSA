#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

int main(){
    vector<int>arr={3,2,7};
    int k=accumulate(arr.begin(),arr.end(),0);
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
    int minVal=1e9;
    for (int sum=0; sum<=k/2; sum++){
        if (dp[n-1][sum]==true){
            int sum1=sum;
            int sum2=k-sum;
            minVal=min(minVal,abs(sum1-sum2));
        }
    }
    cout<<minVal;
}