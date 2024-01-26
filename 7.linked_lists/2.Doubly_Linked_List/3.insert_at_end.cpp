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
    Node *temp=head;
    while (temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
Node *insertAtEnd(int x,Node *head){
    Node *temp=new Node(x);
    if (head==NULL){
        return temp;
    }
    Node *curr=head;
    while (curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=temp;
    temp->prev=curr;
    return head;
}
int main(){
    head=new Node(10);
    Node *Node2=new Node(20);
    Node *Node3=new Node(30);
    head->next=Node2;
    Node2->prev=head;
    Node2->next=Node3;
    Node3->prev=Node2;
    print(head);
    int x=40;
    head=insertAtEnd(x,head);
    print(head);
}