#include<iostream>
#include<set>
using namespace std;

int main(){
    set<string>s;
    //to insert element
    s.insert("abc");
    s.insert("zsdf");
    s.insert("bcd");
    auto it = s.find("abc");
    if(it!=s.end()){
        cout<<*it<<endl;
        cout<<&it<<endl;
    }
    //s.clear();//clears all the elements from the set
    for (auto it:s){
        cout<<it<<" ";
    }
    //s.erase("zsdf");removes this element
}
//T.O: O(log(n))
//stores unique element in sorted order