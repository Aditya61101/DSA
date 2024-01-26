#include<bits/stdc++.h>
using namespace std;

vector<int> nearestSmallerToRight(int arr[],int n){
    stack<pair<int,int>>s;
    vector<int>v;
    int i=n-1;
    while (i>=0){
        if (s.empty()){
            v.push_back(n);
            s.push({arr[i],i});
            i--;
        }
        else if(arr[i]>s.top().first){
            v.push_back(s.top().second);
            s.push({arr[i],i});
            i--;
        }
        else{
            s.pop();
        }
    }
    reverse(v.begin(),v.end());
    return v;
}
vector<int> nearestSmallerToLeft(int arr[],int n){
    stack<pair<int,int>>s;
    vector<int>v;
    int i=0;
    while (i<n){
        if (s.empty()){
            v.push_back(-1);
            s.push({arr[i],i});
            i++;
        }
        else if (arr[i]>s.top().first){
            v.push_back(s.top().second);
            s.push({arr[i],i});
            i++;
        }
        else{
            s.pop();
        }
    }
    return v;
}
int solve(int arr[],int n){
    vector<int>leftSmaller=nearestSmallerToLeft(arr,n);
    vector<int>rightSmaller=nearestSmallerToRight(arr,n);
    vector<int>width;
    vector<int>area;
    for (int i=0; i<n; i++){
        width.push_back(abs(rightSmaller[i]-leftSmaller[i]-1));
    }
    for (int j=0; j<n; j++){
        area.push_back(width[j]*arr[j]);
    }
    auto maxValue=max_element(area.begin(),area.end());
    return *maxValue;
}
int main(){
    int height[]={6,2,5,4,5,1,6};
    int n=sizeof(height)/sizeof(height[0]);
    int result=solve(height,n);
    cout<<result;
}
//MAH:
//right[]:NSR() reverse it,left:NSL(),width:right[]-left[]-1
//area[]:width*arr[curr]
//return max in the area array