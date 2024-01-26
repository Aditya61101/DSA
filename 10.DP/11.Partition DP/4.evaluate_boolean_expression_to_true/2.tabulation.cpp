#include<iostream>
#include<vector>
using namespace std;
#define mod 1000000007
#define ll long long

int main(){
    string exp="T^F|T&F^T|F";
    int n=exp.length();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,0)));
    for(int i=n-1;i>=0;i--){
        for(int j=i;j<n;j++){
            if(i==j){
                dp[i][j][0]=(exp[i]=='F');
                dp[i][j][1]=(exp[i]=='T');
            }
            else{
                for(ll ind=i+1;ind<j;ind+=2){
                    ll lt=dp[i][ind-1][1]%mod;
                    ll rt=dp[ind+1][j][1]%mod;
                    ll lf=dp[i][ind-1][0]%mod;
                    ll rf=dp[ind+1][j][0]%mod;
                    if(exp[ind]=='&'){
                        dp[i][j][0]=(dp[i][j][0]+(lt*rf+lf*rt+lf*rf))%mod;
                        dp[i][j][1]=(dp[i][j][1]+(lt*rt))%mod;
                    }
                    else if(exp[ind]=='|'){
                        dp[i][j][0]=(dp[i][j][0]+(lf*rf))%mod;
                        dp[i][j][1]=(dp[i][j][1]+(lt*rf+lf*rt+lt*rt))%mod;
                    }
                    else{
                        dp[i][j][0]=(dp[i][j][0]+(lt*rt+lf*rf))%mod;
                        dp[i][j][1]=(dp[i][j][1]+(lt*rf+lf*rt))%mod;
                    }
                }
            }
        }
    }
    cout<<dp[0][n-1][1];
}
