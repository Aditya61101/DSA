#include<bits/stdc++.h>
using namespace std;

int solve(string &s){
    vector<int>freq(26);
    for(int i=0; i<s.length();i++){
       freq[s[i]-'a']++; 
    }
    sort(freq.begin(),freq.end(),greater<int>());
    int count=0;
    for(int i=0;i<26;i++){
       if(i<=8){
        count+=freq[i];
       }
       else if(i>8&&i<=17){
        count+=2*freq[i];
       }
       else{
        count+=3*freq[i];
       }
    }
    return count;
}
int main(){
    string s="absdcaaadssdfged";
    int result=solve(s);
    cout<<result;
}