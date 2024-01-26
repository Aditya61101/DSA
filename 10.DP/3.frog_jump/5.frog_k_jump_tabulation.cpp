#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int solve(int i,vector<int>&arr,int k){
    int dp[i];
    dp[0]=0;
    for (int in = 1; in < i+1; in++){
        int minStep=INT_MAX;
        for (int j=1; j<=k; j++){
            if (in-j>=0){
                int climb=dp[in-j]+abs(arr[in-j]-arr[in]);
                minStep=min(minStep,climb);
            }
        }
        dp[in]= minStep;
    }
    return dp[i];
}
int main(){
    int n;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int k=2;
    int result=solve(n-1,arr,k);
    cout<<result;
}
//sum up the additional tasks.