#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int>&ip,vector<int>&op,int i,int sum){
    if(ip.size()==i){
        if (sum==0){
             for(auto &e:op){
                cout<<e<<" ";
            }
            cout<<endl;
        }
        return;
    }
    vector<int>op1=op;
    vector<int>op2=op;
    int ipEle=ip[i];
    op2.push_back(ipEle);
    solve(ip,op1,i+1,sum);
    if(ipEle<=sum){
        solve(ip,op2,i+1,sum-ipEle);
    }
}
int main(){
    vector<int>ip={10,1,2,7,6,1,5};
    vector<int>op;
    int sum=8;
    solve(ip,op,0,sum);
}