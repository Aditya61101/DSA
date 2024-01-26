#include<iostream>
#include<stack>
using namespace std;

void compareF(stack<int>&s,int temp){
    if (s.empty()||s.top()<=temp){
        s.push(temp);
        return;
    }
    int x=s.top();
    s.pop();
    compareF(s,temp);
    s.push(x);
}
void sortStack(stack<int>&s){
    if (s.size()==1){
        return;
    }
    int temp=s.top();
    s.pop();
    sortStack(s);
    compareF(s,temp);
}
int main(){
    stack<int>s;
    s.push(5);
    s.push(1);
    s.push(0);
    s.push(2);
    sortStack(s);
    cout<<"\nafter sort"<<endl;
    while (!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    } 
}