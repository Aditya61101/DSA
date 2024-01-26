#include<iostream>
#include<vector>
using namespace std;

int main(){
    string s1="babgbag";
    int n1=s1.length();
    string s2="bag";
    int n2=s2.length();
    vector<vector<double>>dp(n1+1,vector<double>(n2+1,0));
    for (int j=0; j<n2+1; j++){
        dp[0][j]=0;
    }
    for (int i=0; i<n1+1; i++){
        dp[i][0]=1;
    }
    for (int i=1; i<n1+1; i++){
        for (int j=1; j<n2+1; j++){
            if (s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<(int)dp[n1][n2];
}
//if all characters of s2 matches it means that j<0 so, we should return 1;
//but if j>=0 and i<0 then all the char of s2 didn't match but the string s1 got exhausted.
//if chars matches then we can either move both the pointers(i-1,j-1) or we can search for another occurrence of that matched character(i-i,j).