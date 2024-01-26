#include<iostream>
#include<vector>
using namespace std;

int solve(int in,vector<int>&ip){
    int prev=ip[0],prev2,curr;
    for (int i=1; i<in+1; i++){
        int pick=ip[i];
        if (i>1){
            pick+=prev2;
        }
        int notPick=prev;
        curr=max(pick,notPick);
        prev2=prev;
        prev=curr;
    }
    return curr;
}
int main(){
    vector<int>ip={2,1,4,9};
    int result=solve(ip.size()-1,ip);
    cout<<result;
}