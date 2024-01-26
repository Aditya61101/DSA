#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int>&ip,vector<int>&op,int i,int sum){
    if (ip.size()==i){
        if (sum==0){
           return 1;
        }
        return 0;
    }
    vector<int>op1=op;
    vector<int>op2=op;
    int ipEle=ip[i];
    op2.push_back(ipEle);
    i++;
    int notTaken=solve(ip,op1,i,sum);
    int taken=0;
    if (ipEle<=sum){
        taken=solve(ip,op2,i,sum-ipEle);
    }
    return notTaken+taken;
}
int main(){
    vector<int>ip={1,2,3,1,5};
    vector<int>op;
    int sum=3;
    int result=solve(ip,op,0,sum);
    cout<<result;
}