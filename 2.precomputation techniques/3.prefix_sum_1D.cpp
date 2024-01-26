/*Given array arr of N integers, given Q queries and in each query given L and R print sum of array elements from index L to R(L,R included)*/

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int sum=0;
    int N;
    cin>>N;
    int arr[N];
    vector<int>v;

    for (int i = 0; i < N; i++){
        cin>>arr[i];
        sum+=arr[i];
        v.push_back(sum);
    }

    int q;
    cin>>q;
    while (q--){
        int l,r;
        cin>>l>>r;
        cout<<v[r]-v[l]+arr[l]<<"\n";
    }
}