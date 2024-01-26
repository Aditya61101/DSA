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
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
Node *insertInSort(int x,Node *head){
    Node *temp=new Node(x);
    if (head==NULL){
        return temp;
    }
    //if first node is smaller than the given input
    if (head->data>=x){
        temp->next=head;
        return temp;
    }
    Node *curr=head;
    while(curr->next!=NULL&&curr->next->data<=x){
        curr=curr->next;
    }
    temp->next=curr->next;
    curr->next=temp;
    return head;
}
int main(){
    head=new Node(10);
    Node *temp1=new Node(20);
    Node *temp2=new Node(30);
    Node *temp3=new Node(40);
    head->next=temp1;
    temp1->next=temp2;
    temp2->next=temp3;
    print(head);
    int x=25;
    head=insertInSort(x,head);
    print(head);
}