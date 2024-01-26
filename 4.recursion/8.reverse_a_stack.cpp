#include<iostream>
#include<stack>
using namespace std;

void insertF(stack<int>&s,int temp){
    if(s.empty()){
        s.push(temp);
        return;
    }
    int x=s.top();
    s.pop();
    insertF(s,temp);
    s.push(x);
}
void reverseStack(stack<int>&s){
    if (s.size()==1){
        return;
    }
    int temp=s.top();
    s.pop();
    reverseStack(s);
    insertF(s,temp);
}
int main(){
    stack<int>s;
    s.push(2);
    s.push(1);
    s.push(4);
    s.push(3);
    s.push(5);
    s.push(10);
    reverseStack(s);
    while (!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}