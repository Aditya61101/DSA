#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solve(vector<int>&v,int i,int j,vector<vector<int>>&dp){
    if (i>j){
        return 0;
    }
    if (dp[i][j]!=-1){
        return dp[i][j];
    }
    int minVal=1e9;
    for (int k=i; k<=j; k++){
      int cost=v[j+1]-v[i-1]+solve(v,i,k-1,dp)+solve(v,k+1,j,dp);
      minVal=min(minVal,cost);
    }
    return dp[i][j]=minVal;
}
int main(){
    vector<int>v={1,3,5,4};
    int lenI=v.size();
    int stickL=7;
    v.push_back(stickL);
    v.insert(v.begin(),0);
    sort(v.begin(),v.end());
    int n=v.size();
    vector<vector<int>>dp(n,vector<int>(n,-1));
    int result=solve(v,1,lenI,dp);
    cout<<result;
}
//the cut array is sorted in order to segregate the sticks and solve them independently.
//to insert at any position we use insert function.