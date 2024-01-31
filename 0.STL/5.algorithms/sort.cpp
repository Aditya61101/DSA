#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[3];
    for (size_t i = 0; i < n; i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
     for (size_t i = 0; i < n; i++){
        cout<<arr[i];
    }
}
//sort(arr+x,arr+y);sorts the array arr elements between xth element and yth element i.e (x,y) elements.
//sort(arr,arr+n);sorts the whole array arr.
//quick,heap,insertion sort
//for sorting whole vectors: sort(v.begin(),v.end())
