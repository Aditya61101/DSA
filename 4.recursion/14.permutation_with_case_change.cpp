#include<iostream>
#include<string>
using namespace std;

void solve(string ip,string op,int i){
    if (i==ip.length()){
        cout<<op<<" ";
        return;
    }
    string op1=op;
    string op2=op;
    char letter = toupper(ip[i]);
    op1.push_back(ip[i]);
    op2.push_back(letter);
    solve(ip,op1,i+1);
    solve(ip,op2,i+1);
}
int main(){
    string ip="ab";
    string op="";
    solve(ip,op,0);
}