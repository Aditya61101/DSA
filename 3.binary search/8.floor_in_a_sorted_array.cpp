#include<bits/stdc++.h>
using namespace std;

int searchingFunction(int arr[],int n,int key){
    int low = 0,high = n-1;
    while (low<=high){
        int mid=low+(high-low)/2;
        if (arr[mid]==key){
            return mid;
        }
        else if (arr[mid]>key){
            high = mid-1;
        }
        else{
            if (arr[mid+1]>key){
                return mid;
            }
            low=mid+1; 
        }
    }
}
int main(){
    int arr[] = {1,2,3,4,8,10,10,12,29};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key=5;
    int result = searchingFunction(arr,n,key);
    cout<<result;
}
//the floor of required element will be present in such a manner that the just right element will be greater than the required element.