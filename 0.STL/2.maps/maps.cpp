#include <iostream>
#include <map>
using namespace std;

void printMap(map<string,int>m){
    cout<<m.size()<<endl;
    for (auto &it : m){
        cout << it.first << " " << it.second << endl;
    }
}
int main(){
    map<int, string> m;
    m[1] = "abc";//O(log(n))
    m[5] = "bca";
    m[3] = "acb";
    m.insert(make_pair(4, "cba"));
    m.insert({85, "bac"});
    m[6];//{6,0}
    // printMap(m);
    auto it = m.find(6);//return pointer to that key-value pair if present,O(log(n))
    if (it==m.end()){
        cout<<"no value";
    }
    else{
    cout<<(*it).second;
    }
    m.erase(6);//erases the pair with key 5(if present otherwise shows segmentation fault) from map m
    //m.clear();clears the contents of map 'm'
    map<string,int>key_string;
    int n;
    cin>>n;
    for (size_t i = 0; i < n; i++){
        string s;
        cin>>s;
        key_string[s]=i;
    }
    printMap(key_string);
    
}
// map is a key-value pair STL
//  ordered maps are automatically sorted acc. to the key
// it is implemented using red-black tree.
// iterator+1 is not allowed in this case as values are not stored in contagious locations
//for map with key as string T.C is O(string.size()*log(n))