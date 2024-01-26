#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>weight={2,4,6};
    vector<int>price={5,11,13};
    int n=price.size();
    int W=10;
    vector<vector<int>>dp(n,vector<int>(W+1,0));
    for (int w=0; w<W+1; w++){
        if (weight[0]<=w){
            dp[0][w]=(price[0]*(w/weight[0]));
        }
        else{
            dp[0][w]=-1e9;
        }
    }
    for (int i=1; i<n; i++){
        for (int w=0; w<W+1; w++){
            int notTake=dp[i-1][w];
            int take=-1e9;
            if (weight[i]<=w){
                take=price[i]+dp[i][w-weight[i]];
            }
            dp[i][w]=max(take,notTake);
        }
    }
    cout<<dp[n-1][W];
}