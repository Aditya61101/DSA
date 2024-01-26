//return true if s1==s2 else return false
// '?' means chars are equal, '*' means 0 to any length of string s2 is equal to s1.
#include<iostream>
#include<vector>
using namespace std;

bool solve(string &s1,string &s2,int i,int j,vector<vector<int>>&dp){
    if (i<0&&j<0){
        return true;
    }
    if (i<0&&j>=0){
        return false;
    }
    if (j<0&&i>=0){
        for (int index=i; index>=0; index--){
            if (s1[index]!='*'){
                return false;
            }
        }
        return true;
    }
    if (dp[i][j]!=-1){
        return dp[i][j];
    }
    if (s1[i]==s2[j]||s1[i]=='?'){
        return dp[i][j]=solve(s1,s2,i-1,j-1,dp);
    }
    if (s1[i]=='*'){
        bool notIncludeStar=solve(s1,s2,i-1,j,dp);
        bool includeStar=solve(s1,s2,i,j-1,dp);
        return dp[i][j]=notIncludeStar|includeStar;
    }
    return dp[i][j]=false;
}
int main(){
    string s1="ab*?cd",s2="abdefcd";
    int n1=s1.length(),n2=s2.length();
    vector<vector<int>>dp(n1,vector<int>(n2,-1));
    bool result=solve(s1,s2,n1-1,n2-1,dp);
    cout<<result;
}