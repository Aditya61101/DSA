#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        stack<int>st,ast;
        for(int i=0;i<s.length();i++){
            if(s[i]=='*') {
                ast.push(i);
            } else if(s[i]=='(') {
                st.push(i);
            } else {
                if(!st.empty()) st.pop();
                else if(!ast.empty()) ast.pop();
                else return false;
            }
        }
        // for (((*** and ***((( kinds of condition
        while(st.size()&&ast.size()){
            // if '*' is present before '(' then we can't close it and hence 's' not a valid parenthesis string
            if(st.top()>ast.top()) return false;
            st.pop(); ast.pop();
        }
        return st.empty();
    }
};