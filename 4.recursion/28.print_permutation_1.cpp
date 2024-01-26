#include<iostream>
#include<vector>
#include<set>
using namespace std;

set<vector<int>>allPer;
void solve(vector<int>&ip,vector<int>&op,vector<bool>&chk){
    if(ip.size()==op.size()){
        //  allPer.insert(op);
        for (auto e:op){
            cout<<e<<" ";
        }
        cout<<'\n';
        return;
    }
    for (int i=0; i<ip.size();i++){
        if(chk[i]!=true){
            op.push_back(ip[i]);
            chk[i]=true;
            solve(ip,op,chk);
            chk[i]=false;
            op.pop_back();
        }
    }
}
int main(){
    vector<int>ip={1,2,3};
    vector<int>op;
    vector<bool>chk={false};
    solve(ip,op,chk);
    for (auto &v:allPer){
        for (auto &e:v){
            cout<<e<<" ";
        }
        cout<<"\n";
    }
}