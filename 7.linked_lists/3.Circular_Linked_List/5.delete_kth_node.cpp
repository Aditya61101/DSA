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
Node *deleteKth(Node *head,int k){
    if (head==NULL){
        return NULL;
    }
    if (head->next==head&&k==1){
        delete(head);
        return NULL;
    }
    if (k==1){
        head->data=head->next->data;
        Node *temp=head->next;
        head->next=head->next->next;
        delete(temp);
        return head;
    }
    //for k>1
    int count=1;
    Node *temp=head;
    while (count<k-1){    
        temp=temp->next;
        count++;
    }
    Node *curr=temp;
    temp->next=temp->next->next;
    delete(curr->next);
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
    int k=2;
    head=deleteKth(head,k);
    print(head);
}