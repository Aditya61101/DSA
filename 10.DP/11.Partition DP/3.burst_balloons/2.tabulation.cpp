#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>coins={3,1,5,8};
    int n=coins.size();
    coins.insert(coins.begin(),1);
    coins.push_back(1);
    vector<vector<int>>dp(n+2,vector<int>(n+2,0));
    for (int i=n; i>=1; i--){
        for (int j=1; j<=n; j++){
            if (i>j){
                continue;
            }
            int maxCoins=-1e9;
            for (int k=i;k<=j;k++){
                int totalCoins=coins[i-1]*coins[k]*coins[j+1]+dp[i][k-1]+dp[k+1][j];
                maxCoins=max(maxCoins,totalCoins);
            }
            dp[i][j]=maxCoins;
        }
    }
    cout<<dp[1][n];
}