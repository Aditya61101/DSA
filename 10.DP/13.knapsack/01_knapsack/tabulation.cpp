#include<bits/stdc++.h>
#define vi vector<int>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORIn(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

int main(){
    vi wt = {1,3,4,5};
    vi val = {1,4,5,7};
    int n = wt.size();
    int W = 7;
    vector<vi>dp(n+1,vi(W+1,-1));
    FOR(r,0,n+1){
        FOR(c,0,n+1){
            //since base case value is 0
            if(r==0||c==0)
                dp[r][c]=0;
        }
    }
    //r->n, c->W
    FOR(r,1,n+1){
        FOR(c,1,W+1){
            if(wt[r-1]<=c){
                int take = val[r-1]+dp[r-1][c-wt[r-1]];
                int notTake = dp[r-1][c];
                dp[r][c]=max(take,notTake);
            } else{
                dp[r][c] = dp[r-1][c];
            }
        }
    }
    cout<<dp[n][W];
}
// if(wt[n-1]<=W){
//         int take = val[n-1]+solve(dp,wt,val,W-wt[n-1],n-1);
//         int notTake = solve(dp,wt,val,W,n-1);
//         return dp[n][W] = max(take,notTake);
//     } else{
//         return dp[n][W] = solve(dp,wt,val,W,n-1);
//     }
//replace n->r and W->c inside the loop