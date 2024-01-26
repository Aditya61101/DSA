#include<bits/stdc++.h>
using namespace std;

int subString(string &s){
    int i=0,j=0,maxSize=0;
    unordered_map<char,int>m;
    while (j<s.length()){
        m[s[j]]++;
        if(j-i+1==m.size()){
        maxSize=max(maxSize,j-i+1);
        }
        else if (j-i+1>m.size()){
            while (j-i+1>m.size()){
                m[s[i]]--;
                if (m[s[i]]==0){
                    m.erase(s[i]);
                }
                i++;
            }
        }  
        j++;
    }
    return maxSize;   
}

int main(){
    string s="abaacdbab";
    int result = subString(s);
    cout<<result;
}