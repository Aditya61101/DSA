#include<bits/stdc++.h>
using namespace std;

int ceilCalc(int arr[],int n,int key){
   
    int low = 0,high=n-1;
    while (low<=high){
        int mid = low+(high-low)/2;
        if (arr[mid]==key){
            return arr[mid];
        }
        else if (arr[mid]>key){
            if (arr[mid-1]<key){
                return arr[mid];
            }
            high=mid-1;
        }
        else{
            low=mid+1;
        }        
    }
}
int floorCalc(int arr[],int n,int key){
    
    int low = 0,high=n-1;
    while (low<=high){
        int mid = low+(high-low)/2;
        if (arr[mid]==key){
            return arr[mid];
        }
        else if (arr[mid]>key){
            high=mid-1;
        }
        else{
            if (arr[mid+1]>key){
                return arr[mid];
            }
            low=mid+1;
        }        
    }
}
int minDifference(int arr[],int n,int key){
    int resultCeil = ceilCalc(arr,n,key);
    int resultFloor = floorCalc(arr,n,key);
    if (abs(resultCeil-key)>abs(resultFloor-key)){
        return resultFloor;
    }
    return resultCeil;
}
int main(){
    int arr[] = {1,2,3,6,10,10,12,29};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 5;
    int result = minDifference(arr,n,key);
    cout<<result;
}
//minimum difference element can always either be floor or the ceil or the element itself.
//if the searched element is not present in the array then after the conclusion of binary search the high pointer points at the floor and the low pointer points at the ceil of the searched element. 