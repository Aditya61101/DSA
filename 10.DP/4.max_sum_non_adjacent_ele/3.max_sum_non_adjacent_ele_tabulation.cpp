#include<iostream>
#include<vector>
using namespace std;

int solve(int in,vector<int>&ip){
    int dp[in+1];
    dp[0]=ip[0];
    for (int i = 1; i < in+1; i++){
        int pick=ip[i];
        if (i>1){
            pick+=dp[i-2];
        }
        int notPick=dp[i-1];
        dp[i]=max(pick,notPick);
    }
    return dp[in];
}
int main(){
    vector<int>ip={2,1,4,9};
    int result=solve(ip.size()-1,ip);
    cout<<result;
}