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
Node *reverseKGroup(Node *head,int k){
    if(!head)
        return NULL;
        
    Node *curr=head, *next=NULL, *prev=NULL;
    int count=0;
    //counting to see if enough nodes are available for getting reversed or not
    while(curr!=NULL&&count<k){
        curr=curr->next;
        count++;
    }
    //if count<k then enough nodes aren't available
    if(count<k){
        return head;
    }
    // if available then we reverse upto k length only
    curr=head;
    for(int i=0;i<k;i++){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head->next=reverseKGroup(curr,k);
    return prev;
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
    print(head);
    int k=3;
    head=reverseKGroup(head,k);
    print(head);
}
//T.C=O(n),A.S=O(n/k)