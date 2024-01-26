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
Node *insertAtBegin(int x, Node *head){
    Node *temp=new Node(x);
    temp->next=head;
    head=temp;
    return head;
}
int main(){
    head=new Node(10);
    Node *temp1=new Node(20);
    Node *temp2=new Node(30);
    head->next=temp1;
    temp1->next=temp2;
    print(head);
    int x=5;
    head=insertAtBegin(x,head);
    print(head);
}