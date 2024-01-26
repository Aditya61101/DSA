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
Node *insertAtEnd(int x, Node *head){
    Node *iterator=head;
    Node *temp=new Node(x);
    //case when the linked list is empty
    if(head==NULL){
        head=temp;
        return head;
    }
    while(iterator->next!=NULL){
        iterator=iterator->next;
    }
    iterator->next=temp;
    return head;
}
int main(){
    head=new Node(10);
    Node *temp1=new Node(20);
    Node *temp2=new Node(30);
    head->next=temp1;
    temp1->next=temp2;
    print(head);
    int x=40;
    head=insertAtEnd(x,head);
    print(head);
}
//temp!=NULL => it moves the temp pointer to the NULL
//temp->next!=NULL => it moves the temp pointer to the last node.