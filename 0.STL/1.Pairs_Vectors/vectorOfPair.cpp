#include <iostream>
#include <vector>
#include<utility>
using namespace std;

void printVector(vector<pair<int, int>> &v)
{   cout<<"elements are";
    int n = v.size(); // current size of vector
    for (size_t i = 0; i < n; i++) {
        cout << v[i].first << " " << v[i].second;
        cout << endl;
    }
    cout << endl;
}
int main(){
    vector<pair<int, int>> v;
    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++){
        // int x, y;
        // cin >> x >> y;
        // v.push_back({x, y});
        pair<int,int>p;
        cin>>p.first>>p.second;
        v.push_back(p);
    }
    printVector(v);
}