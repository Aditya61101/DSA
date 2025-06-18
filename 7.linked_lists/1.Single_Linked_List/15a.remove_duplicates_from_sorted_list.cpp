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
        cout<<"linked list is empty :("<<"\n";
        return;
    }
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
Node *removeDuplicates(Node *head){
    if (head==NULL){
        return NULL;
    }
    Node *curr=head,*prev=NULL;
    while (curr->next!=NULL){
        if(curr->data==curr->next->data){
            Node *second=curr;
            if(prev!=NULL){
                prev->next=curr->next;
            }
            else{
                head=head->next;
            }
            curr=curr->next;
            delete(second);
        }
        else{
            prev=curr;
            curr=curr->next;
        }
    }
    return head;
}
int main(){ 
    head=new Node(10);
    Node *temp1=new Node(10);
    Node *temp2=new Node(20);
    Node *temp3=new Node(20);
    Node *temp4=new Node(30);
    Node *temp5=new Node(40);
    head->next=temp1;
    temp1->next=temp2;
    temp2->next=temp3;
    temp3->next=temp4;
    temp4->next=temp5;
    print(head);
    head=removeDuplicates(head);
    print(head);
}