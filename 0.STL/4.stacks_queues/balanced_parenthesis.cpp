// balanced parenthesis
#include <iostream>
#include <stack>
#include<unordered_map>
#include <string>
using namespace std;

unordered_map<char,int>symbols={{'(',-1},{'[',-2},{'{',-3},{')',1},{']',2},{'}',3}};

string isBalanced(string s){

    int i = 0;
    stack<char>st;

    while (i!=s.length()){
        if (symbols[s[i]]<0){
            st.push(s[i]);
        }
        else if(!st.empty()&&(symbols[s[i]]+symbols[st.top()]==0)){
            st.pop();        
        }
        else{
            return "No";
        }
        i++;
    }
    if (st.empty()){
        return "Yes";
    }
    else{
        return "No";
    }
}
int main(){
    string parenthesis = "({[()]})";
    cout<<isBalanced(parenthesis);
}

// put the opening parenthesis in the stack and for every closing parenthesis check if the stack contains opening parenthesis or not.
// opening parenthesis criteria: stack should be empty after traversal
// closing parenthesis criteria: for each closing parenthesis there should be an opening parenthesis in stack.
//  while (i != parenthesis.length()){

//         if (parenthesis[i] == '(' || parenthesis[i] == '{' || parenthesis[i] == '['){
//             s.push(parenthesis[i]);
//         }
//         else{
//             if (parenthesis[i] == ')' && s.top() == '(' && !s.empty()){
//                 s.pop();
//             }
//             else if (parenthesis[i] == '}' && s.top() == '{' && !s.empty()){
//                 s.pop();
//             }
//             else if (parenthesis[i] == ']' && s.top() == '[' && !s.empty()){
//                 s.pop();
//             }
//             else{
//                 cout << "parenthesis are not balanced :(";
//                 flag = 1;
//                 break;
//             }
//         }
//         i++;
//     }
//     if (flag == 0 && s.empty()){
//         cout << "parenthesis are balanced :)";
//     }
//     else{
//         cout << "parenthesis are not balanced :(";
//     }
