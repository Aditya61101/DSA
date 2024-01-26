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
Node *deleteLastNode(Node *head){
    Node *temp=head;
    //if LL is empty
    if (head==NULL){
        return head;
    }
    //if single node is present
    if (head->next==NULL){
        head=NULL;
        delete(temp);
        return head;
    }
    while (temp->next->next!=NULL){
        temp=temp->next;
    }
    delete(temp->next);
    temp->next=NULL;
    return head;
}
int main(){
    head=new Node(10);
    Node *temp1=new Node(20);
    Node *temp2=new Node(30);
    head->next=temp1;
    temp1->next=temp2;
    print(head);
    head=deleteLastNode(head);
    print(head);
}
