#include<iostream>
#include<unordered_map>
using namespace std;

int maxToysPicked(string s){
    int i=0,j=0,maxValue=0;
    unordered_map<char,int>m;

    while (j<s.length()){
        if (m.find(s[j])==m.end()){
            m.insert({s[j],1});
        }
        else{
            m[s[j]]++;
        }
        if (m.size()<2){
            j++;
        }
        else if(m.size()==2){
            maxValue = max(maxValue,j-i+1);
            j++;
        }
        else if(m.size()>2){ 
            while (m.size()>2){
                m[s[i]]--;
                if (m[s[i]]==0){
                    m.erase(s[i]);
                }
                i++; 
            }
            j++;
        } 
    }
    return maxValue;
}
int main(){
    string s = "abaccab";
    int result = maxToysPicked(s);
    cout<<result;
}