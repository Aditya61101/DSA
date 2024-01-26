#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main(){
    vector<int>v={10,9,2,5,3,7,18,101};
    int n=v.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for (int i=n-1; i>=0; i--){
        for (int prevI=i-1; prevI>=-1; prevI--){
            int take=0;
            if (prevI==-1||v[i]>v[prevI]){
                take=1+dp[i+1][i+1];
            }
            int notTake=dp[i+1][prevI+1];
            dp[i][prevI+1]=max(take,notTake);
        }
    }
    cout<<dp[0][0];
}