#include<bits/stdc++.h>
using namespace std;

pair<int,int> search2DArray(int arr[][4],int m,int n,int key){
    int low=0,high=n-1;
    while(low<=m-1&&high>=0){
        if(arr[low][high]==key){
            return {low,high};
        }
        else if (arr[low][high]>key){
            //to go one column left
            high--;
        }
        else{
            //to go one row down
            low++;
        }
    }
    return {-1,-1};
}
int main(){
    int m=4,n=4;
    int arr[4][4]={{10,20,30,40},{15,25,35,45},{27,29,37,48},{32,33,39,50}};
    int key=29;
    pair<int,int> result = search2DArray(arr,m,n,key);
    cout<<result.first<<","<<result.second;
}