#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<string>q;
    q.push("abc");
    q.push("asd");
    q.push("ssasa");
    q.push("dasas");

    while (!q.empty()){
        cout<<"front: "<<q.front()<<endl;
        cout<<"back: "<<q.back()<<endl;
        cout<<"size: "<<q.size()<<endl;
        q.pop();
    }
}
//FIFO
//q.front()=> print the front-most element
//q.back() => print the back-most element
//q.size() => prints the latest size of the queue
//q.pop() => removes the front-most element
//q.push() => adds an element to the front 