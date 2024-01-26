#include<bits/stdc++.h>
using namespace std;

int descendingSorted(int arr[],int n,int key){
    int low = 0, high = n-1;
    while (low<=high){
        int mid = low + (high-low)/2;
        if (arr[mid]==key){
            return mid;
        }
        else if (arr[mid]>key){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}

int main(){
    int arrDesc[] = {10,9,8,7,6,5,4,3,2,1};
    int n = sizeof(arrDesc)/sizeof(arrDesc[0]);
    int key = -13;
   int result = descendingSorted(arrDesc,n,key);
   cout<<result;

}