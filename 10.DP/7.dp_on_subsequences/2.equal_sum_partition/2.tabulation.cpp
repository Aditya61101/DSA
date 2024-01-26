#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>arr={1,2,3,4};
    int k=4;
    int n=arr.size();
    if (k%2!=0){
        cout<<false;
        return 0;
    }
    int actualTarget=k/2;
    vector<vector<bool>>dp(n,vector<bool>(actualTarget+1,false));
    for (int i=0; i<n; i++){
        dp[i][0]=true;
    }
    dp[0][arr[0]]=true;
    for (int i=1; i<n; i++){
        for (int sum=1; sum<actualTarget+1; sum++){
            bool notTaken=dp[i-1][sum];
            bool taken=false;
            if (sum>=arr[i]){
                taken=dp[i-1][sum-arr[i]];
            }
            dp[i][sum]=notTaken|taken;
        }
    }
    cout<<dp[n-1][actualTarget];
}