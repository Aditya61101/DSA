#include<iostream>
#include<vector>
using namespace std;

int solve(int in,vector<int>&ip){
    if (in==0)
        return ip[in];
    if (in<0)
        return 0;
        
    int pick=ip[in]+solve(in-2,ip);
    int notPick=solve(in-1,ip);
    return max(pick,notPick);
}
int main(){
    vector<int>ip={1,2,4};
    int result=solve(ip.size()-1,ip);
    cout<<result;
}