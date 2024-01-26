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
void nthFromEnd(int n,Node *head){
    if (head==NULL){
        cout<<"";
        return;
    }
    int size=0;
    Node *temp=head;
    // to get the size of the LL
    while (temp!=NULL){
        size++;
        temp=temp->next;
    }
    if (n>size){
        cout<<"";
        return;
    }
    temp=head;
    int count=1;
    while(count<size-n){
        temp=temp->next;
        count++;
    }
    cout<<temp->next->data; 
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
    int n=2;
    nthFromEnd(n,head);
}