#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
static bool dp[100][100];

bool solve(vector<int>&arr,int i,int target){
    if (target==0){
        return true;
    }
    if (i==0){
        return (arr[0]==target);
    }
    bool notTaken=solve(arr,i-1,target);
    bool taken=false;
    if (target>=arr[i]){
        taken=solve(arr,i-1,target-arr[i]);
    }
    return taken|notTaken;
}
int main(){
    vector<int>arr={1,2,3,4};
    int k=4;
    int n=arr.size();
    if (k%2!=0){
        cout<<false;
        return 0;
    }
    int actualTarget=k/2;
    memset(dp,-1,sizeof(dp));
    bool result=solve(arr,n-1,actualTarget);
    cout<<result;
}