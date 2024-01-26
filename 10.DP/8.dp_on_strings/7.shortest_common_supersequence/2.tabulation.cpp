#include<iostream>
#include<vector>
using namespace std;

int main(){
    string s1="brute";
    int n1=s1.length();
    string s2="groot";
    int n2=s2.length();
    vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
    for (int j=0; j<n2+1; j++){
        dp[0][j]=0;
    }
    for (int i=0; i<n1+1; i++){
        dp[i][0]=0;
    }
    for (int i=1; i<n1+1; i++){
        for (int j=1; j<n2+1; j++){
            if (s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                continue;
            }
            int notMatchMoveI=dp[i-1][j];
            int notMatchMoveJ=dp[i][j-1];
            dp[i][j]=max(notMatchMoveI,notMatchMoveJ);
        }
    }
    cout<<n1+n2-dp[n1][n2];
}
//we did shifting of index.