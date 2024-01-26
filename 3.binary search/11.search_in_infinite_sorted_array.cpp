#include<bits/stdc++.h>
using namespace std;

int finiteBinarySearch(int arr[],int low,int high,int key){
    int lowF = low, highF = high;
    while (lowF<=highF){
        int mid = lowF + (highF-lowF)/2;
        if (arr[mid]==key){
            return mid;
        }
        else if (arr[mid]>key){
            highF = mid-1;
        }
        else{
            lowF = mid+1;
        }
    }
}
int infiniteSortedArray(int arr[],int key){
    int low =0,high=1;
    while(arr[high]<key){
            low=high;
            high*=2;
        }
        int result = finiteBinarySearch(arr,low,high,key);
        return result;
}
int main(){
    int arr[] = {2,3,10,19,22,32,33,34,35,90,100,110,200,210,211};//cant make this infinite :(
    int key =90;
    int result = infiniteSortedArray(arr,key);
    cout<<result;
}
//start with low:0, high:1 and then compare whether the given key is greater than high or not if yes then move high to 2*high and low to previous high till this condition becomes false. When this condition will become false then we will have a finite array containing the require element and so we can apply the normal binary search.