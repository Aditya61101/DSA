#include<iostream>
#include<vector>
using namespace std;

bool solve(vector<int>&ip,vector<int>&op,int i,int sum){
    if (ip.size()==i){
        if (sum==0){
             for (auto e:op){
                cout<<e<<" ";
            }
            cout<<endl;
            return true;
        }
        return false;
    }
    vector<int>op1=op;
    vector<int>op2=op;
    int ipEle=ip[i];
    op2.push_back(ipEle);
    i++;
    if(solve(ip,op1,i,sum)==true){
        return true;
    }
    if (solve(ip,op2,i,sum-ipEle)==true){
        return true;
    }
    return false;
}
int main(){
    vector<int>ip={1,2,3,1,5};
    vector<int>op;
    int sum=10;
    solve(ip,op,0,sum);
}