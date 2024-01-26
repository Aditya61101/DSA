#include<bits/stdc++.h>
using namespace std;

int uniqueChars(string &s,int k){
    int i=0,j=0,maxValue=0;
    unordered_map<char,int>m;
    while (j<s.size()){
        m[s[j]]++;
        if(m.size()==k){
            maxValue=max(maxValue,j-i+1);
        }
        else if(m.size()>k){ 
            while(m.size()>k){
                m[s[i]]--;
                if(m[s[i]]==0){
                    m.erase(s[i]);
                }
                i++; 
            }
        }
        j++;
    }
    return maxValue;
}
int main(){
    string s = "aabacbebebe";
    int k=3;
    int result = uniqueChars(s,k);
    cout<<result;
}