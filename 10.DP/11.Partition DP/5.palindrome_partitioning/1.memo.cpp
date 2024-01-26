//find minimum no. of partitions of a string such that every partition is a palindrome.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPalindrome(int i,int j,string &s){
    int n=j-i+1,k=0;
    while (k<=n/2){
        if (s[k]!=s[n-k-1]){
            return false;
        }
        k++;
    }
    return true;
}
int solve(string &s,int i,vector<int>&dp){
    if (i==s.length()){
        return 0;
    }
    if (dp[i]!=-1){
        return dp[i];
    }
    int minVal=1e9;
    for (int j=i; j<s.length();j++){
        if (isPalindrome(i,j,s)){
            int ways=1+solve(s,j+1,dp);
            minVal=min(minVal,ways);
        }
    }
    return dp[i]=minVal;
}
int main(){
    string exp="bababcbadcede";
    // string exp="abc";
    int n=exp.length();
    vector<int>dp(n,-1);
    int result=solve(exp,0,dp)-1;
    cout<<result;
}