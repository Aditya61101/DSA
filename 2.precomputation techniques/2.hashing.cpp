/*given an array arr of N integers. Given Q queries, and in each query given a number x, print count of that no. in that array. */
//1sec = 10^7 computations
#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    
    int N;
    cin>>N;
    int arr[N];
    unordered_map<int,int>m;

    for (size_t i = 0; i < N; i++){
        cin>>arr[i];
        m[arr[i]]++;
    }
    
    int q;
    cin>>q;
    while (q--){
        int x;
        cin>>x;
        cout<<"count: "<<m[x]<<endl;
    }
}