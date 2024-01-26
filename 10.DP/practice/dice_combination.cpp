#include<iostream>
#include<vector>
#define ll long long
#define vi vector<int>
using namespace std;

int solve(vi dice,int n,int i,ll sum){
    if(sum==n)
        return 1;
    if(sum>n||i<0)
        return 0;
    int notTake = solve(dice,n,i-1,sum);
    int take = 0;
    if(sum+dice[i]<=n)
        take = solve(dice,n,i,sum+dice[i]);
    // int takePrev = 0;
    // if (i > 0 && sum + dice[i-1] <= n) {
    //     takePrev = solve(dice,n,i,sum+dice[i-1]);
    // }
    return take+notTake;
}
int main(){
    ll n,sum=0;
    cin>>n;
    vi dice={1,2,3,4,5,6};
    cout<<solve(dice,n,5,sum);
}