#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

set<vector<int>>allPer;
void solve(vector<int>&ip,int index){
    if (index==ip.size()){
        allPer.insert(ip);
        return;
    }
    for (int i = index; i < ip.size(); i++){
        swap(ip[i],ip[index]);
        solve(ip,index+1);
        swap(ip[i],ip[index]);
    }
}
int main(){
    vector<int>ip={1,2,3};
    solve(ip,0);
    for (auto v:allPer){
        for (auto e:v){
            cout<<e<<" ";
        }
        cout<<"\n";
    }
}