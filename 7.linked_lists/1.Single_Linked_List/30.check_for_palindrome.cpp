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

bool isPalindrome(Node *head1,Node *head2){
    Node *curr1=head1,*curr2=head2;
    while(curr2!=NULL){
        if(curr1->data!=curr2->data){
            return false;
        }
        curr1=curr1->next;
        curr2=curr2->next;
    }
    return true;
}
void reverseFromMiddle(Node *temp,Node *head){
    Node *first=NULL,*curr=temp->next,*second=curr->next;
    while(curr!=NULL){
        curr->next=first;
        first=curr;
        curr=second;
        if(second!=NULL){
            second=second->next;
        }
    }
    cout<<isPalindrome(head,first);
}
//for even nodes the middle node will be the first out of 2 middle nodes.
void findMiddle(Node *head){
    Node *fast=head,*slow=head;
    while(fast->next!=NULL&&fast->next->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    reverseFromMiddle(slow->next,head);
}
int main(){
    Node *node1=new Node(2);
    Node *node2=new Node(3);
    Node *node3=new Node(3);
    Node *node4=new Node(2);
    Node *node5=new Node(2);
    Node *node6=new Node(3);
    Node *node7=new Node(5);
    Node *node8=new Node(2);
    head=node1;
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next=node5;
    node5->next=node6;
    node6->next=node7;
    node7->next=node8;
    findMiddle(head);
}