#include<bits/stdc++.h>
using namespace std;

vector<int>maxValue(int arr[],int n,int k){
    vector<int>result;
    queue<int>store;
    int i=0,j=0;
    while(j<n){
        //checking if the current element is greater than the first element store in the queue if it is then we will remove that element from the queue.
        if(!store.empty()&&arr[j]>store.front()){
            store=queue<int>();//empty the queue
        }
        store.push(arr[j]);
        if(j-i+1==k){
          result.push_back(store.front());
          //if the largest element has become the first element of the window it means for further subsequent subarrays it wont be the part so we should remove it.
          if(arr[i]==store.front()){
            store.pop();
          }
          i++;
        }
        j++;
    }
    return result;
}
int main(){
    int arr[]={1,3,-1,-3,5,3,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k=3;
    vector<int>value = maxValue(arr,n,k); 
    for(auto it:value){
        cout<<it<<" ";
    }
}