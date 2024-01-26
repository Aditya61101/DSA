#include<bits/stdc++.h>
using namespace std;

char searchNextAlphabet(char arr[],int n,char key){
    
    int low = 0,high = n-1;
    while (low<=high){
        int mid = low+(high-low)/2;
        if (arr[mid]==key){
            if (mid!=n-1){
            return arr[mid+1];
            }
            return '#';
        }
        else if(arr[mid]>key){
            if(arr[mid-1]<key){
                return arr[mid];
            }
            high=mid-1;
        }
        else{
            low = mid+1;
        }
    }
}

int main(){
    char arr[] = {'a','c','f','h','i'};
    int n = sizeof(arr)/sizeof(arr[0]);
    char key = 'h';
    char result = searchNextAlphabet(arr,n,key);
    if (result=='#'){
        cout<<"alphabet is the last element in the array";
        return 0;
    }
    cout<<result;
}