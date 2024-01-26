#include<bits/stdc++.h>
using namespace std;

void solve(string &s1,string &s2){
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    if(s1==s2){
        cout<<"yes";
        return;
    }
    cout<<"no";
}

int main(){
    string s1="aab";
    string s2="aba";
    solve(s1,s2);
}
// int sumS2=0,sumS1=0;
    // for (int i = 0,j=0; i < s2.length()||j<s1.length(); i++,j++){
    //     sumS2+=s2[i]+'0'-'0';
    //     sumS1+=s1[j]+'0'-'0';
    // }
    // if (sumS1==sumS2){
    //     cout<<"yes";
    //     return;
    // }
    // cout<<"no";
//O(n) approach