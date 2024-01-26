#include<iostream>
#include<vector>
using namespace std;

void solve(int k,vector<int>&v,int index){
    if (v.size()==1){
        cout<<v[0];
        return;
    }
    //for circular iteration
    index=(index+k-1)%v.size();
    //to erase the element at index position
    v.erase(v.begin()+index);
    solve(k,v,index);
}
int main(){
    int n=40,k=7;
    vector<int>v;
    for (int i = 0; i<n; i++){
        v.push_back(i+1);
    }
    solve(k,v,0);
}