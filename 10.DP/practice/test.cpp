#include<bits/stdc++.h>
using namespace std;

vector<int>dp(10000,-1);
// vector<bool>isCalculated(10000,false);
int solve(int n){
    if(n==1 || n==2) return 1;
    // if(isCalculated[n]==true) return dp[n];
    // isCalculated[n]=true;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=solve(n-1)+solve(n-2);
}
int main(){
    int n=5;
    cout<<solve(n);
}