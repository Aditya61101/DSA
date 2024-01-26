#include<bits/stdc++.h>
using namespace std;

int firstOccurrence(int arr[],int n,int key){
    
    int low = 0, high = n-1,index=-1;
    while (low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]==key){
            index = mid;
            high = mid-1;
            // if (arr[high]==key){
            //     index = high;
            // }
        }
        else if (arr[mid]>key){
            high = mid-1;
        }
        else{
            low = mid+1;
        }   
    }
    return index;
}
int lastOccurrence(int arr[],int n,int key){

    int low = 0, high = n-1,index=-1;
    while (low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]==key){
            index = mid;
            low = mid+1;
            // if (arr[low]==key){
            //     index = low;
            // }
        }
        else if (arr[mid]>key){
            high = mid-1;
        }
        else{
            low = mid+1;
        } 
    }
    return index;
}
int countOccurrence(int arr[],int n,int key){
    int firstIndex = firstOccurrence(arr,n,key);
    int lastIndex = lastOccurrence(arr,n,key);
    cout<<"first occurrence: "<<firstIndex<<endl;
    cout<<"last occurrence: "<<lastIndex<<endl;
    int count = lastIndex - firstIndex + 1;

    if (lastIndex==-1||firstIndex==-1){
        return -1;
    }
    
    return count;
}

int main(){
    int arr[] = {1,2,2,2,3,3,4,5,6,6,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 2;
    int result = countOccurrence(arr,n,key);
    cout<<"no. of occurrence: "<<result;
}