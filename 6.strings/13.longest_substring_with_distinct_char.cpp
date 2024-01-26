#include<iostream>
#include<vector>
using namespace std;

int solve(string &str){
    int n=str.length(),res=0;
    vector<int>prev(256,-1);//int count[256]={-1};
    int i=0;
    for (int j = 0; j<n; j++){
        i=max(i,prev[str[j]]+1);
        int maxEnd=j-i+1;
        res=max(res,maxEnd);
        prev[str[j]]=j;
    }
    return res;
}
int main(){
    string str="abaacdbab";
    cout<<solve(str);
}
/* //below line of code shifts the starting index to the place where repeated char was found +1.
        i=max(i,prev[str[j]]+1);
        int maxEnd=j-i+1;//window length calculation
        res=max(res,maxEnd);//max window length
        prev[str[j]]=j;//updating the str value in prev vector to its initial index. */