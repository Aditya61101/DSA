#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>v={1,7,8,4,5,6,-1,9};
    int n=v.size();
    vector<int>op;
    op.push_back(v[0]);
    for (int i=1; i<n; i++){
        if (v[i]>op.back()){
            op.push_back(v[i]);
        }
        //else part is the binary search part for finding ceil or the v[i]
        else{
            auto ind=lower_bound(op.begin(),op.end(),v[i])-op.begin();
            op[ind]=v[ind];
        }
    }
    cout<<op.size();
}
//1.search for the current element or the ceil value of current element of v in created op.
//2.if their is no ceil value then push that current element in op else replace that ceil value with the current element of v.
//3.print size of op.
//note: op doesn't contain original elements of lis