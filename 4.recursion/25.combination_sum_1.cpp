#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>>totalOP;
void solve(vector<int>&ip,vector<int>&op,int i,int sum){
    if (ip.size()==i){
        if (sum==0){
            totalOP.push_back(op);
        }
        return;
    }
    vector<int>op1=op;
    vector<int>op2=op;
    int ipEle=ip[i];
    if (ipEle<=sum){
        op2.push_back(ipEle);
        solve(ip,op2,i,sum-ipEle);
    }
    // else{
    //     op2.pop_back();
    // }
    i++;
    solve(ip,op1,i,sum);
}
int main(){
    vector<int>ip={10,1,2,7,6,1,5};
    vector<int>op;
    int sum=8;
    solve(ip,op,0,sum);
    for (auto v:totalOP){
        for (auto e:v){
            cout<<e<<" ";
        }
        cout<<endl;
    }
}