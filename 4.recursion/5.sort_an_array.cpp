#include<iostream>
using namespace std;

void compareF(int arr[],int i,int j){
    if (i==j){
        return;
    }
    if (arr[i]>arr[j]){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
    }
    else{
        i++;
    }
    compareF(arr,i,j);
}
void sortArray(int arr[],int low,int size){ 
    //base case
    if(size==0){
        return;
    }
    //hypothesis
    sortArray(arr,0,size-1);
    //induction
    int i=0;
    compareF(arr,i,size);
}
int main(){
    int arr[]={5, 3, 1, 9, 8, 2, 4, 7, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    sortArray(arr,0,n-1);
    for (size_t i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
}