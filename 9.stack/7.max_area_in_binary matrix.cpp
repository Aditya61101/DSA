#include<iostream>
#include<stack>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

vector<int> nearestSmallerToRight(vector<int>&arr,int n){
    stack<pair<int,int>>s;
    vector<int>v;
    int i=n-1;
    while (i>=0){
        if (s.empty()){
            v.push_back(n);
            s.push({arr[i],i});
            i--;
        }
        else if (arr[i]>s.top().first){
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
vector<int> nearestSmallerToLeft(vector<int>&arr,int n){
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
int areaHistogram(vector<int>&arr,int n){
    vector<int>leftSmaller=nearestSmallerToLeft(arr,n);
    vector<int>rightSmaller=nearestSmallerToRight(arr,n);
    vector<int>width;
    vector<int>area;
    for (int i = 0; i < n; i++){
        width.push_back(rightSmaller[i]-leftSmaller[i]-1);
    }
    for (int j = 0; j < n; j++){
        area.push_back(width[j]*arr[j]);
    }
    auto maxValue=max_element(area.begin(),area.end());
    return *maxValue;
}
int solve(int arr[4][4],int r,int c){
    vector<int>v;
    int maxV=INT_MIN;
    for (int j = 0; j < c; j++){
        v.push_back(arr[0][j]);
    }
    maxV=max(maxV,areaHistogram(v,v.size()));
    for (int i = 1; i < r; i++){
        for (int j = 0; j < c; j++){
            if (arr[i][j]==1){
                v[j]+=arr[i][j];
            }
            else{
                v[j]=arr[i][j];
            }
        }
        maxV=max(maxV,areaHistogram(v,v.size()));
    }
    return maxV;
}
int main(){
    int r=4,c=4;
    int matrix[4][4]={{0,1,1,0},{1,1,1,1},{1,1,1,1},{1,1,0,0}};
    int result=solve(matrix,r,c);
    cout<<result;
}
