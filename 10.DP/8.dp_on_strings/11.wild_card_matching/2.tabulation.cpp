//return true if s1==s2 else return false
// '?' means chars are equal '*' means 0 to any length of string s2 is equal to s1.
#include<iostream>
#include<vector>
using namespace std;

int main(){
    string s1="ab*?cd",s2="abdefcd";
    int n1=s1.length(),n2=s2.length();
    vector<vector<bool>>dp(n1+1,vector<bool>(n2+1,false));
    dp[0][0]=true;
    for (int j=1; j<n2+1; j++){
        dp[0][j]=false;
    }
    for (int i=1; i<n1+1; i++){
        bool flag=true;
        for(int index=1; index<=i; index++){
            if(s1[index-1]!='*'){
                flag=false;
                break;
            }
        }
        dp[i][0]=flag;
    }
    for (int i=1; i<n1+1; i++){
        for (int j=1; j<n2+1; j++){
            if (s1[i-1]==s2[j-1]||s1[i-1]=='?'){
                dp[i][j]=dp[i-1][j-1];
            }
            else if (s1[i-1]=='*'){
                bool notIncludeStar=dp[i-1][j];
                bool includeStar=dp[i][j-1];
                dp[i][j]=notIncludeStar|includeStar;
            }
            else dp[i][j]=false;
        }
    }
    cout<<dp[n1][n2];
}