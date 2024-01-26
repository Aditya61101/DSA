#include<iostream>
using namespace std;

void solve(int n,int count0,int count1,string op){
    if(count0+count1==n){
        cout<<op<<endl;
        return;
    }
    if(count1!=n){
        string op1=op;
        op1.push_back('1');
        solve(n,count0,count1+1,op1);
    }
    if(count1>count0){
        string op2=op;
        op2.push_back('0');
        solve(n,count0+1,count1,op2);
    }
}
int main(){
    int n=3;
    string op="";
    solve(n,0,0,op);
}