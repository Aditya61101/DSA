#include<bits/stdc++.h>
using namespace std;

int countRotation(int arr[],int n){ 
    int low=0,high=n-1;
    while (low<=high){
        int mid=low+(high-low)/2;
        // took % n to resolve corner cases
        int prev = (mid+n-1)%n;
        int next = (mid+1)%n;
        //for maximum element
        if (arr[mid]>arr[next]&&arr[mid]>arr[prev]){
            return abs(n-1-mid);
        }
        if (arr[mid]<arr[prev]){
            high=prev;
        }
        else if(arr[mid]<arr[next]){
            low=next;
        }
    }
}
int main(){
    int arr[]= {8,7,6,5,4,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int result = countRotation(arr,n);
    cout<<"no. of times the given sorted array is rotated: "<<result;
}
//for minimum element
//arr[mid]<arr[mid+1]&&arr[mid]<arr[mid-1]