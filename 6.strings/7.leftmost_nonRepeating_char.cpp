#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int solve(string str){
    
    int count[256]={0},minVal=INT_MAX;
    for (int i = str.length()-1; i >=0; i--){
        count[str[i]-'a']++;
        if (count[str[i]-'a']==1){
            minVal=min(minVal,i);
        }
    }
    if (minVal==INT_MAX){
            return -1;
    }
    return minVal;
}
int main(){
    string str="abcd";
    int result = solve(str);
    cout<<result;
}