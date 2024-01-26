#include<iostream>
#include<stack>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

vector<int>calcGreatestLeft(int arr[],int n){
    vector<int>v;
    stack<int>s;
    int i=0;
    while (i<n){
        if (s.empty()){
            s.push(arr[i]);
            v.push_back(-1);
            i++;
        }
        if (arr[i]<=s.top()){
            v.push_back(s.top());
            i++;
        }
        else{
            s.pop();
        } 
    }
    return v;
}
vector<int>calcGreatestRight(int arr[],int n){
    vector<int>v;
    stack<int>s;
    int i=n-1;
    while (i>=0){
        if (s.empty()){
            s.push(arr[i]);
            v.push_back(-1);
            i--;
        }
        if (arr[i]<=s.top()){
            v.push_back(s.top());
            i--;
        }
        else{
            s.pop();
        } 
    }
    reverse(v.begin(),v.end());
    return v;
}
int solve(int arr[],int n){
    vector<int>greatestLeft=calcGreatestLeft(arr,n);
    vector<int>greatestRight=calcGreatestRight(arr,n);
    int sum=0;
    for (int i = 0; i < n; i++){
        if (greatestLeft[i]==-1||greatestRight[i]==-1){
            sum+=0;
        }
        else{
            int minVal=min(greatestLeft[i],greatestRight[i]);
            int area=abs(minVal-arr[i]);
            sum+=area;
        }
    }
    return sum;
}
int main(){
    int arr[]={3,1,2,4,0,1,3,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    int result=solve(arr,n);
    cout<<result;
}