#include<bits/stdc++.h>
using namespace std;

int peakElement(int arr[],int n){
    int low=0,high=n-1;
    while (low<=high){
        //to avoid integer overflow
        int mid = low+(high-low)/2;
       if (arr[mid]>arr[mid+1]&&arr[mid]>arr[mid-1]){
            return mid;
        }
        else if(arr[mid]<arr[mid+1]){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
        //corner cases
        if (mid=n-1&&arr[mid]>arr[mid-1]){
            return mid;
        }
        else if(mid=0&&arr[mid]>arr[mid+1]){
            return mid;
        }
    }
}
int main(){
    int arr[]={5,10,20,15};
    int n = sizeof(arr)/sizeof(arr[0]);
    int result = peakElement(arr,n);
    cout<<result;
}
//peak element: a element greater than both of its neighbour.