#include<iostream>
#include<stack>
using namespace std;

stack<int>s,ss;
void push(int x){
    s.push(x);
    if (ss.empty()||ss.top()>=x){
        ss.push(x);
    }
}
int pop(){
    if (s.empty()){
        return -1;
    }
    //it means the element that we are going to pop is the min element of the current stack s.
    if (s.top()==ss.top()){
        ss.pop();
    }
    int temp=s.top();
    s.pop();
    return temp;
}
int getMin(){
    if (ss.empty()){
        return -1;
    }
    return ss.top();
}
int main(){
     int arr[]={18,19,29,15,16,26,5,32};
    push(arr[0]);
    push(arr[1]);
    push(arr[2]);
    push(arr[3]);
    int result=getMin();
    cout<<result<<endl;
    pop();
    result=getMin();
    cout<<result<<endl;
    push(arr[4]);
    push(arr[5]);
    push(arr[6]);
    result=getMin();
    cout<<result<<endl;
    pop();
    result=getMin();
    cout<<result;
}