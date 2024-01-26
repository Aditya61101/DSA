#include<bits/stdc++.h>
using namespace std;

int searchInBitonic(int arr[],int low,int high,int key){
     int lowL=low,highL=high;
     while (lowL<=highL){
        int mid=lowL+(highL-lowL)/2;
        if (arr[mid]==key){
            return mid;
        }
        else if (arr[mid]>key){
            highL=mid-1;
        }
        else{
            lowL=mid+1;
        }
     }
    return -1;
}
int maxElement(int arr[],int n,int key){
     int low=0,high=n-1;
    while (low<=high){
        int mid=low+(high-low)/2;
        if (arr[mid]>arr[mid+1]&&arr[mid]>arr[mid-1]){
            int resultLeft=searchInBitonic(arr,0,mid,key);
            int resultRight=searchInBitonic(arr,mid+1,n-1,key);
            if (resultLeft!=-1){
                return resultLeft;
            }
            return resultRight;  
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
    int key=4;
    int n=sizeof(arr)/sizeof(arr[0]);
    int result = maxElement(arr,n,key);
    cout<<result;
}
//s1:find the peak element
//s2:divide the array into 2 parts first containing 0 to max index element and second containing max+1 to n-1th index element.
//s3:apply binary search in both the halves.