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
Node *deleteLastNode(Node *head){
    if (head==NULL){
        return NULL;
    }
    if (head->next==NULL){
        delete(head);
        return NULL;
    }
    Node *temp=head;
    while (temp->next!=NULL){
        temp=temp->next;
        if (temp->next->next==NULL){
            temp->next=NULL;
        }
    }
    delete(temp);
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
    head=deleteLastNode(head);
    print(head);
}
//without if condition
// temp->prev->next=NULL;
//if tail node is given
//tail->prev->next=NULL; This is a constant operation