#include<iostream>
using namespace std;

void solve(int open,int close,string op){
    if(open==0&&close==0){
        cout<<op<<" ";
        return;
    }
    if(open!=0){
        string op1=op;
        op1.push_back('(');
        solve(open-1,close,op1);
    }
    if(open<close){
        string op2=op;
        op2.push_back(')');
        solve(open,close-1,op2);
    }
}
int main(){
    int n=3;
    string op="";
    solve(n,n,op);
}