#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

//i is the index of current position and j is the index of the position where we want to jump
int solve(int i,vector<int>&arr,int k){
    if (i==0)
        return 0;
    //Initialize a variable minStep to hold the minimum steps needed to reach the current position.
    int minStep=INT_MAX;
    for (int j=1; j<=k; j++){
        if (i>=j){
            int climb=solve(i-j,arr,k)+abs(arr[i-j]-arr[i]);
            minStep=min(minStep,climb);
        }
    }
    return minStep;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];

    int k=2;
    int result=solve(n-1,arr,k);
    cout<<result;
}
//sum up the additional tasks.