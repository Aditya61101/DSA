#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>weight={3,4,5};
    vector<int>money={30,50,60};
    int W=8;
    int n=weight.size();
    vector<vector<int>>dp(n,vector<int>(W+1,0));
    for (int w=0; w<W+1; w++){
        if (w-weight[0]>=0){
            dp[0][w]=money[0];
        }
        else{
            dp[0][w]=0;
        }
    }
    for(int i=1;i<n;i++){
        for (int w=0; w<W+1; w++){
            int notTake=dp[i-1][w];
            int take=-1e9;
            if(w-weight[i]>=0){
                take=money[i]+dp[i-1][w-weight[i]];
            }
            dp[i][w]=max(take,notTake);         
        }
    }
    cout<<dp[n-1][W];
}