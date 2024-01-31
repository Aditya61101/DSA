#include<iostream>
#include<map>
#include<set>
using namespace std;

int main(){
    map<int,multiset<string>>marks;
    int N;
    cin>>N;
    for (size_t i = 0; i < N; i++){
        string name;
        int mark;
        cin>>name>>mark;
        marks[mark].insert(name);
    }
    for (auto it=marks.rbegin();it!=marks.rend();it++){
       auto &students = it->second;
       auto &marks = it->first;
       for (auto student:students){
           cout<<student<<" "<<marks<<endl;
       }
    }
}
//auto it
//(*it).first=it->first
//marks={{78,{Alice,Eve}},{99,Bob}}