#include<iostream>
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
    //for the last node
    cout<<temp->data;
    cout<<endl;
}
Node *deleteHead(Node *head){
    if (head==NULL){
        return NULL;
    }
    if (head->next==head){
        delete(head);
        return NULL;
    }
    //copying data to 2nd node from 1st node
    head->data=head->next->data;
    //storing 2nd node in temp pointer
    Node *temp=head->next;
    //connecting pseudo 1st node with the 3rd node
    head->next=head->next->next;
    delete(temp);
    return head;
}
int main(){
    Node *head=new Node(10);
    head->next=head;
    Node *Node2=new Node(20);
    head->next=Node2;
    Node2->next=head;
    Node *Node3=new Node(30);
    Node2->next=Node3;
    Node3->next=head;
    print(head);
    head=deleteHead(head);
    print(head);
}