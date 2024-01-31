#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v= {2,3,4,5,6,7};
    //range based loops
    for (auto &x:v){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<*(v.begin())<<endl;//2
    cout<<*(v.end()-1)<<endl;//7

    vector<pair<int,int>> v_pair={{1,2},{3,4},{5,6}};
    for (auto &it:v_pair){
        cout<<it.first<<" "<<it.second<<endl;
    }
}
//here x works as an iterator
//v.begin() => pointer pointing to the first element of a vector
//v.end() => pointer pointing to the (last+1)th position
// x=*(vector<int>::iterator it)
//it++ moves to the next iterator 0->1->so on
//it+1 moves to the next memory location
//for vectors, it++ and it+1 both are same
//(*it).first <=> (it->first)