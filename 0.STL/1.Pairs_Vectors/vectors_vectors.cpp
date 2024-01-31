#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int> &v){                     // by reference
    int n = v.size(); // current size of vector
    for (size_t i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
int main(){
    int N;//v.size()
    cin>>N;
    vector<vector<int>>v;
    for (size_t i = 0; i < N; i++){
        int n;
        cin>>n;
        vector<int>temp;//initially there is no vector in main vector
        for (size_t j = 0; j < n; j++){
            int x;
            cin>>x;
            temp.push_back(x);
        }
        v.push_back(temp);
    }
    for (size_t i = 0; i < N; i++){
        printVector(v[i]);
    } 
}