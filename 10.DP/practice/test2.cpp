#include<bits/stdc++.h>
#define vi vector<int>
#define ll long long
using namespace std;

int solve(vi &v,vi &dp,int i,int n){
    if(i==n) return 0;
    if(dp[i]!=-1) return dp[i];
    int pickCurrentElement = v[i]+solve(v,dp,i+2,n);
    int skipCurrentElement = solve(v,dp,i+1,n);
    return dp[i] = max(pickCurrentElement,skipCurrentElement);
}
int main(){
    int n;
    cin>>n;
    vi v(n);
    vi dp(n,-1);
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<solve(v,dp,0,n);
}