#include<bits/stdc++.h>
using namespace std;

int orderNotKnown(vector<int>&arr,int key){
    int n=arr.size();
    int low=0,high=n-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if (arr[mid]==key){
            return mid;
        }
        else if(arr[mid]>key){
            //for descending case
            if (arr[0]>arr[n-1]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        else{
            //for descending case
              if (arr[0]>arr[n-1]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }  
        }
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr;
    for (size_t i = 0; i < n; i++){
        cin>>arr[i];
    }
    int key;
    cin>>key;
    int result = orderNotKnown(arr,key);
    cout<<result;
}