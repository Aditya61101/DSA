#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>ip={2,5,7,8,10};
    int n=ip.size();
    vector<vector<int>>dp(n,vector<int>(n+1,0));
    for (int s=0; s<n+1; s++){
        dp[0][s]=s*ip[0];
    }
    for (int i=1; i<n; i++){
        for (int s=0; s<n+1; s++){
            int take=-1e9;
            int rodLength=i+1;
            if(rodLength<=s){
                take=ip[i]+dp[i][s-rodLength];
            }
            int notTake=dp[i-1][s];
            dp[i][s]=max(take,notTake);
        }
    }
    cout<<dp[n-1][n];
}