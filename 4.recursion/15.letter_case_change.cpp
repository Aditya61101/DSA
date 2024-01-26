#include<iostream>
#include<string>
using namespace std;

void solve(string ip,string op,int i){
    if (i==ip.length()){
        cout<<op<<" ";
        return;
    }
    if ('0'<=ip[i]&&'9'>=ip[i]){
        op.push_back(ip[i]);
        solve(ip,op,i+1);
    }
    else{
        string op1=op;
        string op2=op;
        char letter;
        if(islower(ip[i])){
            letter=toupper(ip[i]);
        }
        else if(isupper(ip[i])){
            letter=tolower(ip[i]);
        }
        //without changing the case
        op1.push_back(ip[i]);
        //with changing the case
        op2.push_back(letter);
        solve(ip,op1,i+1);
        solve(ip,op2,i+1);
    }
}
int main(){
    string ip="a1B2",op="";
    solve(ip,op,0);
}