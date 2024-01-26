#include<iostream>
#include<cstring>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

static int dp[100][100][100];
int solve(vector<int>&arr,int i,int sum,int sumR){
  if(i==0){
    int taken=abs((sum-arr[0])-(sumR+arr[0]));
    int notTaken=abs(sum-sumR);
    return min(taken,notTaken);
  }
  if(dp[i][sum][sumR]!=-1){
    return dp[i][sum][sumR];
  }
  int notTaken=solve(arr,i-1,sum,sumR);
  int taken=0;
  if (arr[i]<=sum){
    taken=solve(arr,i-1,sum-arr[i],sumR+arr[i]);
  }
  return dp[i][sum][sumR]=min(notTaken,taken);
}
int main(){
    vector<int>arr={3,2,7};
    int n=arr.size();
    int sum=accumulate(arr.begin(),arr.end(),0);
    memset(dp,-1,sizeof(dp));
    int result=solve(arr,n-1,sum,0);
    cout<<result;
}