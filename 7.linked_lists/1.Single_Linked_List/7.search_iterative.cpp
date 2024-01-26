#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x){
        data=x;
        next=NULL;
    }
};
Node *head=NULL;

void print(Node *temp){
    while (temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int searchIterative(int x,Node *head){
    Node *temp=head;
    int pos=1;
    while(temp!=NULL){
        if(temp->data==x){
            return pos;
        }
        pos++;
        temp=temp->next;
    }
    delete(temp);
    return -1;
}
int main(){
    head=new Node(10);
    Node *temp1=new Node(30);
    Node *temp2=new Node(50);
    head->next=temp1;
    temp1->next=temp2;
    int x=20;
    int pos=searchIterative(x,head);
    cout<<pos;
}