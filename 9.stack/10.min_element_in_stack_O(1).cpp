#include<iostream>
#include<stack>
#include<climits>
using namespace std;

stack<int>s;
int minPrev;
int minCurr=INT_MAX;
void push(int x){
    s.push(x);
    if (minCurr==INT_MAX||minCurr>=x){
        minPrev=minCurr;
        minCurr=x;
    }
}
int pop(){
    if (s.empty()){
        return -1;
    }
    //it means the element that we are going to pop is the min element of the current stack s.
    if (s.top()==minCurr){
        minCurr=minPrev;
    }
    int temp=s.top();
    s.pop();
    return temp;
}
int getMin(){
    if (s.empty()){
        return -1;
    }
    return minCurr;
}
int main(){
    int arr[]={18,19,29,15,16,26,5,32};
    push(arr[0]);
    push(arr[1]);
    push(arr[2]);
    push(arr[3]);
    int result=getMin();
    cout<<result<<endl;
    int popped= pop();
    cout<<popped<<endl;
    result=getMin();
    cout<<result<<endl;
    push(arr[4]);
    push(arr[5]);
    push(arr[6]);
    result=getMin();
    cout<<result<<endl;
    popped=pop();
    cout<<popped<<endl;
    result=getMin();
    cout<<result;
}