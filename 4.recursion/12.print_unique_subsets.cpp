#include<iostream>
#include<unordered_set>
#include<algorithm>
using namespace std;

unordered_set<string>subset;
void printSubsets(string ip,string op){
     if (ip.length()==0){
        sort(op.begin(),op.end());
        subset.insert(op);
        return;
    }
    string op1=op;
    string op2=op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    printSubsets(ip,op1);
    printSubsets(ip,op2);    
}
int main(){
    string ip="44414",op="";
    printSubsets(ip,op);
    for (auto i:subset){
        cout<<i<<endl;
    }
}
//print subsets = print PowerSet = print all subsequences
//abc => a,b,c,ab,bc,abc => substring
//abc => ac,bc,abc,a,b,c,abc => subsequences
//abc => ac,ca,cb,bc,a,b,c,abc,"" => subsets