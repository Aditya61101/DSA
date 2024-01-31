#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int>s;
    s.push(2);
    s.push(3);
    s.push(8);
    s.push(85);
    s.push(12);
    while (!s.empty()){
        cout<<"size"<<s.size()<<endl;
        cout<<"top"<<s.top()<<endl;
        s.pop();
    }
}
//s.empty() returns a boolean
//s.top() prints the latest element in stack
//s.pop() removes the topmost element
//push,pop,top,size :operations on a stack
//LIFO, only the last element can be accessed