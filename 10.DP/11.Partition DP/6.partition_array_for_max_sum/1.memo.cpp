#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int solve(vector<int>&v,int i,int n,int k,vector<int>&dp){
    if (i==v.size()){
        return 0;
    }
    if (dp[i]!=-1){
        return dp[i];
    }
    int len=0,maxVal=-1e9,maxSum=-1e9;
    for(int index=i; index<min(n,i+k); index++){
        len++;
        maxVal=max(maxVal,v[index]);
        int sum=maxVal*(len)+solve(v,index+1,n,k,dp);
        maxSum=max(sum,maxSum);
    }
    return dp[i]=maxSum;
}
int main(){
    vector<int>v={1,15,7,9,2,5,10};
    int maxP=3;
    int n=v.size();
    vector<int>dp(n,-1);
    int result=solve(v,0,n,maxP,dp);    
    cout<<result;
}