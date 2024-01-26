#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x){
        data=x;
    }
};
Node *head1=NULL;
Node *head2=NULL;

void print(Node *head){
    Node *curr=head;
    while(curr){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    cout<<"\n";
}
Node *mergeSortedList(Node *head1,Node *head2){
    if (head1==NULL){
        return head2;
    }
    else if(head2==NULL){
        return head1;
    }
    Node *head=NULL,*tail=NULL;
    Node *curr1=head1,*curr2=head2;
    if(curr1->data>=curr2->data){
        head=tail=curr2;
        curr2=curr2->next;
    }
    else{
        head=tail=curr1;
        curr1=curr1->next;
    }
    while(curr2!=NULL&&curr1!=NULL){
        if(curr2->data>=curr1->data){
            tail->next=curr1;
            tail=curr1;
            curr1=curr1->next;
        }
        else{
            tail->next=curr2;
            tail=curr2;
            curr2=curr2->next;
        }
    }
    if(curr1==NULL){
        tail->next=curr2;
    }
    else{
        tail->next=curr1;
    }
    return head;
}
int main(){
    Node *node1=new Node(10);
    Node *node2=new Node(20);
    Node *node3=new Node(30);
    Node *node4=new Node(5);
    Node *node5=new Node(25);
    head1=node1;
    head2=node4;
    node1->next=node2;
    node2->next=node3;
    node4->next=node5;
    Node *mergedHead=mergeSortedList(head1,head2);
    print(head1);
    print(head2);
    print(mergedHead);
}
//find which one is smaller, connect tail to the smaller one and then equate tail to it and then move that pointer ahead.
//if the loop ends, then the node which hasn't become NULL, tail's next will connect to it. 