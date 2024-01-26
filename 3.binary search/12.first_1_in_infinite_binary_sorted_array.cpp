#include<bits/stdc++.h>
using namespace std;

int firstOccurrence(int arr[],int low,int high){
    int lowF = low, highF=high,index=-1;
    while (lowF<=highF){
        int mid = lowF+(highF-lowF)/2;
        if (arr[mid]==1){
            index=mid;
            highF=mid-1;
        }
        else{
            lowF=mid+1;
        }  
    }
    return index;   
}
int infiniteSortedArray(int arr[]){
    int low=0,high=1;
    while (arr[high]<1){
            low=high;
            high*=2;
        }
        int result = firstOccurrence(arr,low,high);
        return result;
}
int main(){
    int arr[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1};//cant make this infinite  :(
    int result = infiniteSortedArray(arr);
    cout<<result;
}