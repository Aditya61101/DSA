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
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
Node *ReverseInGroup(Node *head,int k){
    Node *curr=head,*prevFirst=NULL;
    bool isFirstPass=true;
    while(curr!=NULL){
        Node *first=curr,*prev=NULL;
        int count=0;
        while(curr!=NULL&&count<k){
            Node *second=curr->next;
            curr->next=prev;
            prev=curr;
            curr=second;
            count++;
        }
        //if the first k grps of nodes have been reversed then the prev will be the head of that grp and should also be the head of the entire linked list.
        if(isFirstPass){
            isFirstPass=false;
            head=prev;
        }
        else{
            prevFirst->next=prev;
        }
        prevFirst=first;
    }
    return head;
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
    head=ReverseInGroup(head,k);
    print(head);
}
//T.C=theta(n)