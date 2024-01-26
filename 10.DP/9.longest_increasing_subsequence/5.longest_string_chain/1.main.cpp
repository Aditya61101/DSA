#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool checkPossible(string &s1,string &s2){
    if (s1.size()!=s2.size()+1){
        return false;
    }
    int first=0,second=0;
    while (first<s1.size()){
        if (second<s2.size()&&s1[first]==s2[second]){
            first++,second++;
        }
        else{
            first++;
        }
    }
    if (first==s1.size()&&second==s2.size()){
        return true;
    }
    return false;
}
bool comp(string &s1,string &s2){
    return s1.size()<s2.size(); 
}
int main(){
    vector<string>v={"xbc","pcxbcf","xb","cxbc","pcxbc"};
    sort(v.begin(),v.end(),comp);
    int n=v.size(),maxVal=1;
    vector<int>dp(n,1);
    for (int curr=0; curr<n; curr++){
        for (int prev=0; prev<curr; prev++){
            if (checkPossible(v[curr],v[prev])&&1+dp[prev]>dp[curr]){
                dp[curr]=1+dp[prev];
            }
        }
        if (dp[curr]>maxVal){
            maxVal=dp[curr];
        }
    }
    cout<<maxVal;
}