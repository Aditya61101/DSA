#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int> &v)
{                     // by reference
    int n = v.size(); // current size of vector
    for (size_t i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
int main(){
    int N;
    cin>>N;
    vector<int> v[N];
    for (size_t i = 0; i < N; i++){
        int n;
        cin>>n;//takes input of size of internal vectors
        for (size_t j = 0; j < n; i++){
            int x;
            cin>>x;
            v[i].push_back(x);
        }
    }
    for (size_t i = 0; i < N; i++){
        printVector(v[i]);
    }
    
}