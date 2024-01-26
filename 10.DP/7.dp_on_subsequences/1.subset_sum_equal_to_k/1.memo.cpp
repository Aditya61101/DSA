#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
static int dp[100][100];
bool solve(vector<int>&arr,int i,int k){
    if (k==0){
        return true;
    }
    if (i==0){
        return (arr[0]==k);
    }
    if(dp[i][k]!=-1){
        return dp[i][k];
    }
    bool taken=false;
    if (k>=arr[i]){
        taken=solve(arr,i-1,k-arr[i]);
    }
    bool notTaken=solve(arr,i-1,k);
    return dp[i][k]=taken|notTaken;
}
int main(){
    vector<int>arr={1,2,3,4};
    int k=4;
    int n=arr.size();
    memset(dp,-1,sizeof(dp));
    bool result=solve(arr,n-1,k);
    cout<<result;
}
//in this case, we needed one subseq. to satisfy our criteria thats why we returned true as soon as we see sum=0. we need not to go till the end in this case.