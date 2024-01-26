#include<iostream>
#include<vector>
#include<set>
using namespace std;

multiset<int>subsetSum;
void solve(vector<int>&ip,vector<int>&op,int i){
    if (ip.size()==i){
        int sum=0;
        for (auto e:op){
            sum+=e;
        }
        subsetSum.insert(sum);
        return;
    }
    vector<int>op1=op;
    vector<int>op2=op;
    op2.push_back(ip[i]);
    i++;
    solve(ip,op1,i);
    solve(ip,op2,i);
}
int main(){
    vector<int>ip={2,1,3};
    vector<int>op;
    solve(ip,op,0);
    for (auto sum:subsetSum){
        cout<<sum<<" ";
    }
}