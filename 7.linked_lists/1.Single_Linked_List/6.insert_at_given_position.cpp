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
Node *insertAtPosition(int x, Node *head, int pos){
    Node *nNode=new Node(x);
    Node *curr=head;
    Node *sizeCount=head;
    int count=1,size=1;
    //to calculate the size of linked list in order to check whether the given position is beyond the size of LL or not
    while(sizeCount->next!=NULL){
        sizeCount=sizeCount->next;
        size++;
    }
    if(pos>size+1){
        return head;
    }
    if (pos==1){
        nNode->next=head;
        head=nNode;
        return head;
    }
    while(count<pos-1){
        curr=curr->next;
        count++;
    }
    nNode->next=curr->next;
    curr->next=nNode;
    delete(curr);
    delete(sizeCount);
    return head;
}
int main(){
    head=new Node(10);
    Node *temp1=new Node(30);
    Node *temp2=new Node(50);
    head->next=temp1;
    temp1->next=temp2;
    print(head);
    int x=20;
    int pos=1;
    head=insertAtPosition(x,head,pos);
    print(head);
}