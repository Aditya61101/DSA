#include<iostream>
#include<vector>
#include<map>
#include<utility>
using namespace std;

int main(){
    multimap<int,string>m;
   m.insert({1,"abc"});
    m.insert({1,"cfg"});
    m.insert({1,"aaa"});
    m.insert({3,"asd"});
    for (auto it:m){
        cout<<it.first<<" "<<it.second<<endl;
    }
    

}