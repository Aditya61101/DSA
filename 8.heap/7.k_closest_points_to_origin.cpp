#include<bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int>> pp;

void solve(int arr[4][2],int r,int c,int k){
    priority_queue<pp>maxHeap;
    int i=0;
    while (i<r){
        int dist=sqrt(pow(arr[i][0],2)+pow(arr[i][1],2));
        maxHeap.push({dist,{arr[i][0],arr[i][1]}});
        if (maxHeap.size()>k){
            maxHeap.pop();
        }
        i++;
    }
    while (!maxHeap.empty()){
        cout<<maxHeap.top().second.first<<" "<<maxHeap.top().second.second<<'\n';
        maxHeap.pop();
    }
}
int main(){
    int r=4,c=2,k=2;
    int arr[4][2]={{1,3},{-2,2},{5,8},{0,1}};
    solve(arr,r,c,k);
}