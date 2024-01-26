#include<iostream>
using namespace std;

void reverseArray(int arr[],int i,int n){
    if (i==(n/2)+1){
        return;
    }
    swap(arr[i],arr[n-i-1]);
    reverseArray(arr,i+1,n);
}
int main(){
    int arr[]={1,2,3,4,2,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int i=0;
    reverseArray(arr,i,n);
    for (auto i:arr){
        cout<<i<<" ";
    }
}