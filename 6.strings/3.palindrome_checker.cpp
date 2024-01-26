#include<iostream>
using namespace std;

void solve(string &ip,int i){
    if (i==(ip.length()/2)){
        cout<<"yes";
        return;
    }
    if (ip[i]!=ip[ip.length()-i-1]){
        cout<<"no";
        return;
    }
    solve(ip,i+1); 
}
int main(){
    string ip="ABCCBA";
    solve(ip,0);
}