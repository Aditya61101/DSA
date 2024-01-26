#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int>v={10,9,2,5,3,7,18,101};
    int n=v.size(),maxVal=1,lastIndex=0;
    vector<int>dp(n,1),hash(n);
    for (int curr=0; curr<n; curr++){
        hash[curr]=curr;
        for (int prev=0; prev<curr; prev++){
            if (v[prev]<v[curr]&&1+dp[prev]>dp[curr]){
                dp[curr]=1+dp[prev];
                hash[curr]=prev;            
            }
        }
        if (dp[curr]>maxVal){
            maxVal=dp[curr];
            lastIndex=curr;     
        }
    }
    vector<int>lis;
    lis.push_back(v[lastIndex]);
    while(hash[lastIndex]!=lastIndex){
        lastIndex=hash[lastIndex];
        lis.push_back(v[lastIndex]);
    }
    reverse(lis.begin(),lis.end());
    for (auto &it:lis){
        cout<<it<<" ";
    }
}