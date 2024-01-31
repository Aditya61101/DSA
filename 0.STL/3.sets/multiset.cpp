#include<iostream>
#include<set>
using namespace std;

int main(){
    multiset<string>s;
    s.insert("assad");
    s.insert("saa");
    s.insert("abc");
    s.insert("abc");
    s.insert("saa");
    for (auto it:s){
        cout<<it<<" ";
    }
    cout<<endl;
    auto it = s.find("abc");//returns iterator of first occurrence
    cout<<&it<<endl;
    s.erase(it);//removes the value present at that iterator from the multiset
    cout<<&it<<endl;
    cout<<*it<<endl;
    for (auto it:s){
        cout<<it<<" ";
    }
    cout<<endl;
    s.erase("saa");//removes all the occurrence of saa 
    for (auto it:s){
        cout<<it<<" ";
    }
}
//allows duplicate entries
//stores data in sorted order