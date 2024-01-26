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
Node *Reverse(Node *head){
    if (head==NULL){
        return head;
    }
    Node *first=NULL,*second=head->next;
    while(head!=NULL){
        head->next=first;
        first=head;
        head=second;
        if(second!=NULL){
            second=second->next;
        }
    }
    return first;
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
    print(head);
    head=Reverse(head);
    print(head);
}