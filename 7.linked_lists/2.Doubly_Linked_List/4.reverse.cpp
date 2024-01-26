#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *prev;
    Node *next;
    Node(int x){
        data=x;
        prev=NULL;
        next=NULL;
    }
};
Node *head=NULL;

void print(Node *head){
    Node *temp=head;
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
    Node *curr=NULL;
    Node *prevCurr=NULL;
    while (head!=NULL){
        curr=head;
        //swapping the nodes
        prevCurr=curr->prev;
        curr->prev=curr->next;
        curr->next=prevCurr;
        head=head->prev;
    }
    delete(prevCurr);//deleting extra pointers created
    return curr;
}
int main(){
    head=new Node(10);
    Node *Node2=new Node(20);
    Node *Node3=new Node(30);
    head->next=Node2;
    Node2->prev=head;
    Node2->next=Node3;
    Node3->prev=Node2;
    print(head);
    head=Reverse(head);
    print(head);
}
//in the while loop we are traversing using head=head->prev because due to swapping head's prev has become head's next and vice versa.