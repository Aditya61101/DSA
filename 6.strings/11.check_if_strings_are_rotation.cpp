#include<iostream>
#include<string>
using namespace std;

bool solve(string s1,string s2){
    if (s1.length()!=s2.length()){
        return false;
    }
    string s1Concat=s1.append(s1);
    return s1Concat.find(s2)!=string::npos;
}
int main(){
    string s1="abab",s2="abba";
    cout<<solve(s1,s2);
}
//if index of searched element is not present the find function returns string:npos.