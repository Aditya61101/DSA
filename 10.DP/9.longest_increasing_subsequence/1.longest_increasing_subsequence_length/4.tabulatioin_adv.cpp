#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int>v={10,9,2,5,3,7,18,101};
    int n=v.size(),maxVal=1;
    vector<int>dp(n,1);
    for (int curr=0; curr<n; curr++){
        for (int prev=0; prev<curr; prev++){
            if (v[prev]<v[curr]){
                dp[curr]=max(1+dp[prev],dp[curr]);            
            }   
        }
        maxVal=max(maxVal,dp[curr]);
    }
    cout<<maxVal;
}