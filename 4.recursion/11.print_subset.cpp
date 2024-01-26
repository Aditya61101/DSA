#include<iostream>
#include<string>
using namespace std;

void printSubset(string ip,string op,int i){
    if (i==ip.length()){
        cout<<op<<'\n';
        return;
    }
    string op1=op;
    string op2=op;
    op2.push_back(ip[i]);
    printSubset(ip,op1,i+1);//not taken case
    printSubset(ip,op2,i+1);//taken case
}
int main(){
    string ip="ab";
    string op="";
    printSubset(ip,op,0);
}