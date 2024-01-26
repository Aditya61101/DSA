#include<bits/stdc++.h>
using namespace std;

int searchAroundMax(int arr[],int low,int high,int key){
    int lowRight = low, highRight = high;
    while (lowRight<=highRight){
        int mid = lowRight + (highRight-lowRight)/2;
        if (arr[mid]==key){
            return mid;
        }
        else if(arr[mid]>key){
            highRight = mid-1;
        }
        else{
            lowRight = mid+1;
        }  
    }
    return -1;
}

int findMaxElement(int arr[],int n,int key){
     int low = 0, high = n-1;
    while (low<=high){
        int mid = low + (high-low)/2;
        // took % n to resolve corner cases
        int prev = (mid+n-1)%n;
        int next = (mid+1)%n;
        //for maximum element
        if (arr[mid]>arr[next]&&arr[mid]>arr[prev]){
            int result1 = searchAroundMax(arr,0,mid,key);
            int result2 = searchAroundMax(arr,mid+1,n-1,key);
            if (result1>0){
                return result1;
            }
            else if (result2>0){
                return result2;
            }
            return -1;
        }
        if (arr[mid]<arr[prev]){
            high = prev;
        }
        else if(arr[mid]<arr[next]){
            low = next;
        }
    }
}

int main(){
    int arr[]= {11,12,15,18,2,5,6,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 15;
    int result = findMaxElement(arr,n,key);
    cout<<result;
}
//s1: find the max element
//s2: find the given element in (0,max) part of the array.also find the given element in (max+1,n-1) part of the array.
//s3: one function will return -1 other will return the index or in worst case both wil return -1. 