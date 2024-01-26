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
void detectLoop(Node *head){
    Node *slow=head,*fast=head;
    while (fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        if (slow==fast){
            break;
        }
    }
    if (slow!=fast){
        return;
    }
    //for the length of the loop
    slow=head;
    int count=0;
    while (slow!=fast){
        slow=slow->next;
        count++;
    }
    cout<<count<<endl;
    //to find the first node of the loop
    slow=head;
    Node *fastAlias=fast;
    while (fastAlias!=slow){
        slow=slow->next;
        fastAlias=fastAlias->next;
    }
    cout<<slow->data<<endl;
    //for removing the loop
    slow=head;
    while (slow->next!=fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    fast->next=NULL;
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
    temp5->next=temp2;
    detectLoop(head);
}
//fast pointer will enter the loop before or with slow.
//if fast pointer is k distance ahead of slow when slow enters the loop then after that this distance keeps on increasing by 1.
//when this distance become equal to length of the cycle, they both meet.

//for length of the loop
//fixed one pointer after the meet and traverse the other by keeping the count of the no. of times the loop has been traversed such that they meet again.