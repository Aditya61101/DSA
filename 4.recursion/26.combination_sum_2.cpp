#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

set<vector<int>>totalOP;
void solve(vector<int>&ip,vector<int>&op,int i,int sum){
    if (ip.size()==i){
        if (sum==0){
            totalOP.insert(op);
        }
        return;
    }
    vector<int>op1=op;
    vector<int>op2=op;
    int ipEle=ip[i];
    op2.push_back(ipEle);
    i++;
    solve(ip,op1,i,sum);
    if (ipEle<=sum){
        solve(ip,op2,i,sum-ipEle);
    }
}
int main(){
    vector<int>ip={10,1,2,7,6,1,5};
    sort(ip.begin(),ip.end());
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