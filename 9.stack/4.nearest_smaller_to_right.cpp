#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

vector<int> nearestSmallerToRight(int arr[],int n){
    stack<int>s;
    vector<int>v;
    int i=n-1;
    while (i>=0){
        if (s.empty()){
            v.push_back(-1);
            s.push(arr[i]);
            i--;
        }
        else if (arr[i]>s.top()){
            v.push_back(s.top());
            s.push(arr[i]);
            i--;
        }
        else{
            s.pop();
        }
    }
    reverse(v.begin(),v.end());
    return v;
}
int main(){
    int arr[]={1,5,2,10,9,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>result=nearestSmallerToRight(arr,n);
    for (auto i:result){
        cout<<i<<" ";
    }
}
//traverse the array from right to left, because if we remove s.top(), still we will have assurance that the removed element will never be the nearest smaller element.