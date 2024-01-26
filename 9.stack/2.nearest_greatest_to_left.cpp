#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nearestGreaterToLeft(int arr[],int n){
    stack<int>s;
    vector<int>v;
    int i=0;
    while (i<n){
        if(s.empty()){
            v.push_back(-1);
            s.push(arr[i]);
            i++;
        }
        else if(arr[i]<s.top()){
            v.push_back(s.top());
            s.push(arr[i]);
            i++;
        }
        else{
            s.pop();
        }
    }
    return v;
}
int main(){
    int arr[]={1,5,2,10,9,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>result=nearestGreaterToLeft(arr,n);
    for (auto i:result){
        cout<<i<<" ";
    }
}
//traverse the array from left to right, because if we remove s.top(), still we will have assurance that the removed element will never be the nearest greatest element.