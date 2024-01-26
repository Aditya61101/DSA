#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int main(){
    vector<int>v={1,15,7,9,2,5,10};
    int k=3;
    int n=v.size();
    vector<int>dp(n,0);
    for (int i=n-1; i>=0; i--){
        int len=0,maxVal=-1e9,maxSum=-1e9;
        for(int index=i; index<min(n,i+k); index++){
            len++;
            maxVal=max(maxVal,v[index]);
            int sum=maxVal*(len)+dp[index+1];
            maxSum=max(sum,maxSum);
        }
        dp[i]=maxSum;
    }    
    cout<<dp[0];
}