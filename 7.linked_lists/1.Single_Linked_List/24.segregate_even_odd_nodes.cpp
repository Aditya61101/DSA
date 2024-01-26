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
Node *segregateNodes(Node *temp){
    Node *curr=head;
    Node *oddStart=NULL,*oddEnd=NULL;
    Node *evenStart=NULL,*evenEnd=NULL;
    while(curr!=NULL){
        int x=curr->data;
        if (x%2==0){
            if (evenStart==NULL){
                evenStart=evenEnd=curr;
            }
            else{
                evenEnd->next=curr;
                evenEnd=evenEnd->next;
            }
        }
        else{
            if (oddStart==NULL){
                oddStart=oddEnd=curr;
            }
            else{
                oddEnd->next=curr;
                oddEnd=oddEnd->next;
            }
        }
        curr=curr->next;
    }
    if (evenStart==NULL||oddStart==NULL){
        return head;
    }
    evenEnd->next=oddStart;
    oddEnd->next=NULL;
    return evenStart;
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
    head=segregateNodes(head);
    print(head);
}