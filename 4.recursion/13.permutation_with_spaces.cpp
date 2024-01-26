#include<iostream>
#include<string>
using namespace std;

void solve(string ip,string op,int i){
    if (i==ip.length()-1){
        cout<<op<<",";
        return;
    }
    string op1=op;
    string op2=op;
    op2.push_back(' ');
    i++;
    op1.push_back(ip[i]);
    op2.push_back(ip[i]);
    solve(ip,op1,i);
    solve(ip,op2,i);
}
int main(){
    string ip="123",op="";
    op.push_back(ip[0]);
    solve(ip,op,0);
}