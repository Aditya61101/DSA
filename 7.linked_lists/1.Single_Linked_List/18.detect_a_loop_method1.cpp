#include<bits/stdc++.h>
using namespace std;
 
struct Node{
    int data;
    Node *next;
    bool visited;
    Node(int x){
        data=x;
        next=NULL;
        visited=false;
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
void detectLoop(Node *head){
   Node *curr=head;
    while (curr->next!=NULL){
        if (curr->next->visited){
            cout<<"yes";
            return;
        }
        curr->visited=true;
        curr=curr->next;
    }
    cout<<"no";
}
int main(){ 
    head=new Node(10);
    Node *temp1=new Node(20);
    Node *temp2=new Node(30);
    Node *temp3=new Node(40);
    Node *temp4=new Node(50);
    Node *temp5=new Node(60);
    head->next=temp1;
    temp1->next=temp2;
    temp2->next=temp3;
    temp3->next=temp4;
    temp4->next=temp5;
    // temp5->next=temp1;
    detectLoop(head);
}