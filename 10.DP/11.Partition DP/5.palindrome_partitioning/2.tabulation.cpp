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
int main(){
    string s="bababcbadcede";
    int n=s.length();
    vector<int>dp(n+1,0);
    for (int i=n-1; i>=0; i--){
        int minVal=1e9;
        for (int j=i; j<s.length();j++){
            if (isPalindrome(i,j,s)){
                int ways=1+dp[j+1];
                minVal=min(minVal,ways);
            }
        }
        dp[i]=minVal;
    }    
    cout<<dp[0]-1;
}