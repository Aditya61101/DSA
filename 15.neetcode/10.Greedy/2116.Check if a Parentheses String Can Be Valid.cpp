#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.length();
        if(n%2!=0) return false;
        int open=0,close=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('||locked[i]=='0') open+=1;
            else open-=1;

            if(s[n-i-1]==')'||locked[n-i-1]=='0') close+=1;
            else close-=1;

            if(open<0||close<0) return false;
        }
        return true;
    }
};