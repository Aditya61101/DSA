#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> solve(vector<int>&arr){
    int n=arr.size();
    stack<int>s;
    vector<int>v;
    v.push_back(1);
    int curr=1,prev=0,count=1;
    while(curr<n){
        if(s.empty()){
            s.push(arr[curr]);
        }
        else if(arr[prev]<=s.top()){
            count++;
            if (prev<0){
                v.push_back(count);
                count=1;
                s.pop();
                curr++;
                prev=curr-1;
            }
            else{
                prev--;
            }
        }
        else{
            v.push_back(count);
            count=1;
            s.pop();
            curr++;
            prev=curr-1;
        } 
    }
    return v;
}
int main(){
    vector<int>stock={100,80,60,70,60,75,85};
    vector<int>result=solve(stock);  
    for (auto &e:result){
        cout<<e<<" ";
    }
}
//in this Question we basically stop at the nearest greatest element of the given element.