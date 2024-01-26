#include<bits/stdc++.h>
using namespace std;

void solve(string &s1,string &s2){
    int j=0;
    for (int i=0; i<s1.length()&&j<s2.length(); i++){
        if (s1[i]==s2[j]){
            j++;
        }
    }
    if (j==s2.length()){
        cout<<"yes";
        return;
    }
    cout<<"no";
}
int main(){
    string s1="ABCD";
    string s2="ADB";
    solve(s1,s2);
}