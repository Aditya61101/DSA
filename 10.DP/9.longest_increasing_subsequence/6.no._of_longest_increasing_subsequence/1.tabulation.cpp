#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int main(){
    vector<int>v={1,5,4,3,2,6,7,10,8,9};
    int n=v.size(),maxVal=INT_MIN;
    vector<int>dp(n,1),count(n,1);
    for (int curr=0; curr<n; curr++){
        for (int prev=0; prev<curr; prev++){
            if (v[prev]<v[curr]&&1+dp[prev]>dp[curr]){
                dp[curr]=1+dp[prev];
                count[prev]=count[curr];
            }
            else if (v[prev]<v[curr]&&1+dp[prev]==dp[curr]){
                count[curr]+=count[prev];
            }
        }
        maxVal=max(maxVal,dp[curr]);
    }
    int nos=0;
    for (int i=0; i<n; i++){
        if (maxVal==dp[i]){
            nos+=count[i];
        }
    }
    cout<<nos;
}