#include<bits/stdc++.h>
using namespace std;

int maxElement(int arr[],int n){
    int low=0,high=n-1;
    while (low<=high){
        int mid=low+(high-low)/2;
        if (arr[mid]>arr[mid+1]&&arr[mid]>arr[mid-1]){
            return arr[mid];
        }
        else if (arr[mid]<arr[mid+1]){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
}
int main(){
    int arr[]={1,3,8,12,4,2};
    int n =sizeof(arr)/sizeof(arr[0]);
    int result = maxElement(arr,n);
    cout<<result;
}
//bitonic: first monotonically increasing then decreasing