#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<int,string>m;
    m[1]="abc";
    m[54]="sss";
    m[3]="dmak";
    for (auto it:m){
        cout<<it.first<<" "<<it.second<<endl;
    }
}
//uses hash
//T.O:O(1)
//stores key-value in random order
//useful when for optimal solution and order doesn't matter
