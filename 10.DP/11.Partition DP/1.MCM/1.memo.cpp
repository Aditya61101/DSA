//given the N matrices dimensions, find the min operations to multiply them to a single matrix.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solve(vector<int>&v,int i,int j,vector<vector<int>>&dp){
    // as there is only one matrix left
    if (i==j){
        return 0;
    }
    if (dp[i][j]!=-1){
        return dp[i][j];
    }
    int minVal=1e9;
    for (int k=i; k<j; k++){
        int steps=v[i-1]*v[k]*v[j]+solve(v,i,k,dp)+solve(v,k+1,j,dp);
        minVal=min(minVal,steps);
    }
    return dp[i][j]=minVal;
}
int main(){
    vector<int>v={10,20,30,40,50};
    int n=v.size();
    vector<vector<int>>dp(n,vector<int>(n,-1));
    int result=solve(v,1,n-1,dp);
    cout<<result;
}
//vector v contains v.size()-1 matrices dimensions.
//1st matrix: v[0]xv[1]
//2nd matrix: v[1]xv[2]
//3rd matrix: v[2]xv[3]
//4th matrix: v[3]xv[4]
//ith matrix: v[i-1]xv[i]
//when i=j, we will have only one matrix to perform an operation which means no operation or return 0.
//here k is the partition variable.