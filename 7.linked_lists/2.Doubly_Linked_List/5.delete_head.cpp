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
Node *deleteHead(Node *head){
    //if node is empty
    if (head==NULL){
        delete(head);
        return NULL;
    }
    //if only one node is present
    if (head->next==NULL){
        delete(head);
        return NULL;
    }
    Node *temp=head;
    temp=temp->next;
    temp->prev=NULL;
    delete(head);
    return temp;
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
    head=deleteHead(head);
    print(head);
}