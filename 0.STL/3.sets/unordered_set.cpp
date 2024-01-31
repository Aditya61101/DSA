#include<iostream>
#include<unordered_set>
using namespace std;

int main(){
    unordered_set<string>s;
    s.insert("sddsa");
    s.insert("sadeqd");
    s.insert("erdw");
    for (auto it:s){
        cout<<it<<" ";
    }   
}
//uses hash_map
//stores in random way
//T.O: O(1)