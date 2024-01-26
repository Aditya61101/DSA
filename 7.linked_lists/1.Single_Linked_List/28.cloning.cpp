#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *random;
    Node(int x){
        data=x;
        next=NULL;
        random=NULL;
    }
};
Node *head=NULL;
Node *random=NULL;
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
Node *clone(Node *head,Node *random){
    
}
int main(){
    head=new Node(17);
    Node *temp1=new Node(15);
    Node *temp2=new Node(8);
    Node *temp3=new Node(12);
    Node *temp4=new Node(10);
    Node *temp5=new Node(5);
    Node *temp6=new Node(4);
    head->next=temp1;
    temp1->next=temp2;
    temp2->next=temp3;
    temp3->next=temp4;
    temp4->next=temp5;
    temp5->next=temp6;
    print(head);
    clone(head,random);
    print(head);
}