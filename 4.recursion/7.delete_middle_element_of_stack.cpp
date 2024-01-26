#include<iostream>
#include<stack>
using namespace std;

void deleteStack(stack<int>&s,int n){
    if (s.size()==(n/2)+1){
        s.pop();
        return;
    }
    int temp=s.top();
    s.pop(); 
    deleteStack(s,n);
    s.push(temp);   
}
int main(){
    stack<int>s;
    s.push(2);
    s.push(1);
    s.push(4);
    s.push(3);
    s.push(5);
    s.push(10);
    int n=s.size();
    deleteStack(s,n);
    while (!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}