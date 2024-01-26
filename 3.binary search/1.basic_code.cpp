#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[],int n,int key){
    int low = 0, high = n-1;
    while (low<=high){
        // int mid = (low+high)/2;
        int mid = low + (high-low)/2;//to avoid overflow
        if (arr[mid]==key){
            return mid;
        }
        else if (arr[mid]>key){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return -1;
}
int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 17;
    int result = binarySearch(arr,n,key);
    cout<<result;

}