#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main(){
    map<pair<string,string>,vector<int>>m;
    int N;
    cin>>N;
    for (size_t i = 0; i < N; i++){
        string f,l;
        int n;//size of the vector to be inserted as the value of the map m 
        cin>>f>>l>>n;
        vector<int>temp;
        for (size_t j = 0; j < n; j++){
            int x;
            cin>>x;
            temp.push_back(x);
        }
        m.insert({{f,l},temp});     
    }
    for (auto pr:m){
        auto &full_name = pr.first;
        auto &list = pr.second;
        cout<<full_name.first<<" "<<full_name.second;
        cout<<endl;
        for (auto &x:list){
            cout<<x<<" ";
        }
    }    
}
//m[{f,l}] is a vector