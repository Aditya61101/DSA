#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int n=s.length();
        int openCount=0,closeCount=0;
        for(int i=0;i<n;i++){
            // Count open parentheses or asterisks
            if(s[i]=='('||s[i]=='*') openCount+=1;
            else openCount-=1;
            // Count close parentheses or asterisks
            if(s[n-i]==')'||s[n-i]=='*') closeCount+=1;
            else closeCount-=1;
            // If at any point open count or close count goes negative, the string is invalid
            if(openCount<0||closeCount<0) return false;
        }
        // If open count and close count are both non-negative, the string is valid
        return true;
    }
};