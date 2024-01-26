#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main(){
    vector<int>v={1,11,2,10,4,5,2,1};
    int n=v.size(),maxVal=INT_MIN;
    vector<int>dpLeft(n,1),dpRight(n,1);
    for (int curr=0; curr<n; curr++){
        for (int prev=0; prev<curr; prev++){
            if (v[prev]<v[curr]&&1+dpLeft[prev]>dpLeft[curr]){
                dpLeft[curr]=1+dpLeft[prev];
            }
        }
    }
    for (int curr=n-1; curr>=0; curr--){
        for (int prev=n-1; prev>curr; prev--){
            if (v[prev]<v[curr]&&1+dpRight[prev]>dpRight[curr]){
                dpRight[curr]=1+dpRight[prev];
            }
        }
        maxVal=max(maxVal,dpLeft[curr]+dpRight[curr]-1);
    }
    cout<<maxVal;   
}
//either increasing or decreasing.