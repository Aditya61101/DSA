#include<bits/stdc++.h>
using namespace std;

//self referential structure 
struct Node{
    int data;
    Node *next;
    //constructor to initialize a node
    Node(int x){
        data=x;
        next=NULL;
    }
};
void print(Node *temp){
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){
    Node *head=new Node(10);
    Node *temp1=new Node(20);
    Node *temp2=new Node(30);
    head->next=temp1;
    temp1->next=temp2;
    print(head);
}
//head,temp1,temp2 are the pointers pointing to the newly created node.