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

void print(Node *head){
    Node *curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
}
Node *deleteNode(Node *head,int x){
    if(head->data==x){
        Node *temp=head;
        head=head->next;
        delete(temp);
    }
    Node *curr=head,*prev=NULL;
    while(curr!=NULL){
        if(curr->data==x){
            Node *temp=curr;
            prev->next=curr->next;
            curr=curr->next;
            delete(temp);
        }
        else{
            prev=curr;
            curr=curr->next;
        }
    }
    return head;
}
int main(){
    Node *node1=new Node(2);
    Node *node2=new Node(5);
    Node *node3=new Node(1);
    Node *node4=new Node(1);
    Node *node5=new Node(2);
    Node *node6=new Node(5);
    Node *node7=new Node(2);
    Node *node8=new Node(2);
    head=node1;
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next=node5;
    node5->next=node6;
    node6->next=node7;
    node7->next=node8;
    int x=2;
    print(head);
    head=deleteNode(head,x);
    cout<<"\n";
    print(head);
}