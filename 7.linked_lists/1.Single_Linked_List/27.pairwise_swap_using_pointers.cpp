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
    if (temp==NULL){
        cout<<"linked list is empty :("<<endl;
        return;
    }
    while (temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
Node *pairSwap(Node *head){
    if (head==NULL||head->next==NULL){
        return head;
    }
    Node *curr=head->next->next;
    Node *prev=head;
    //for swapping first 2 nodes
    head=head->next;
    head->next=prev;
    //for swapping remaining nodes
    while (curr!=NULL&&curr->next!=NULL){
        prev->next=curr->next;
        prev=curr;
        Node *nextCurr=curr->next->next;
        curr->next->next=curr;
        curr=nextCurr;
    }
    //for last node
    prev->next=curr;
    return head;
}
int main(){
    head=new Node(17);
    Node *temp1=new Node(15);
    Node *temp2=new Node(8);
    Node *temp3=new Node(12);
    Node *temp4=new Node(10);
    Node *temp5=new Node(5);
    Node *temp6=new Node(4);
    head->next=temp1;
    temp1->next=temp2;
    temp2->next=temp3;
    temp3->next=temp4;
    temp4->next=temp5;
    temp5->next=temp6;
    print(head);
    pairSwap(head);
    print(head);
}