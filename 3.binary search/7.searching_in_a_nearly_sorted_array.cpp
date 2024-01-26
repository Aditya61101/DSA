#include<bits/stdc++.h>
using namespace std;

int searchingFunction(vector<int>&arr,int key){
    int n=arr.size();
    int low=0,high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if (arr[mid]==key){
            return mid;
        }
        else if(mid+1<=high&&arr[mid+1]==key){
            return mid+1;
        }
        else if(mid-1>=low&&arr[mid-1]==key){
            return mid-1;
        }
        else if(arr[mid]>key){
            high = mid-2;
        }
        else{
            low=mid+2;
        }        
    }
    return -1;
}
int main(){
    vector<int>arr={5,10,30,20,40};
    int key=10;
    int result = searchingFunction(arr,key);
    cout<<result;
}
//nearly sorted: an ith element should be present either at ith, i-1th or i+1th position.