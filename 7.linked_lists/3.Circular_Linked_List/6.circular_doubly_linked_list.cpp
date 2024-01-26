#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *prev;
    Node *next;
    Node(int x){
        data=x;
        prev=NULL;
        next=NULL;
    }
};
Node *head=NULL;

void print(Node *head){
    if (head==NULL){
        cout<<"Linked List is empty :("<<endl;
        return;
    }
    Node *temp=head;
    while (temp->next!=head){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data;
}
int main(){
    Node *head=new Node(10);
    Node *node2=new Node(20);
    Node *node3=new Node(30);
    head->next=node2;
    head->prev=node3;
    node2->next=node3;
    node2->prev=head;
    node3->next=head;
    node3->prev=node2;
    print(head);
}