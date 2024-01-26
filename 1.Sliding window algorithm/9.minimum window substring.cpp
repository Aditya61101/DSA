#include<bits/stdc++.h>
using namespace std;

int minSubString(string &s,string &t){
    int i=0,j=0,minSize=INT_MAX;
    unordered_map<char,int>m;
    for(int i=0; i<t.length(); i++){
        m[t[i]]++;
    }
    int count=m.size();
    while (j<s.length()){
        if(m.find(s[j])!=m.end()){
            m[s[j]]--;
            if(m[s[j]]==0){
                count--;
            }
        }
        if(count==0){
            if (m.find(s[i])==m.end()){
                i++;
            }
            else{
                while(count==0){
                    m[s[i]]++;
                    if(m[s[i]]>0){
                    count++;
                    }
                    i++;
                }
            }
            minSize=min(minSize,j-i+1);
        }
        j++;    
    }
    return minSize;
}
int main(){
    string s="totmtaptat";
    string t = "tta";
    int result =  minSubString(s,t);  
    cout<<result;
}