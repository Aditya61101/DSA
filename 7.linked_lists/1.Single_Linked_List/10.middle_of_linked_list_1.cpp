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
//for even nodes the middle node will be the first out of 2 middle nodes.
int findMiddle(Node *head){
    if (head==NULL){
        return NULL;
    }
    Node *slow=head,*fast=head;
    while(fast->next!=NULL&&fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow->data;
}
int main(){
    head=new Node(10);
    Node *temp1=new Node(5);
    Node *temp2=new Node(20);
    Node *temp3=new Node(15);
    Node *temp4=new Node(25);
    head->next=temp1;
    temp1->next=temp2;
    temp2->next=temp3;
    temp3->next=temp4;
    int midValue=findMiddle(head);
    if (midValue==NULL){
        cout<<"";
    }
    cout<<midValue;
}