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
Node *removeAllDuplicates(Node *head){
    if (head==NULL) return NULL;

    Node* dummy = new Node(0); 
    dummy->next = head; 
    Node* prev = dummy;
    Node* current = head; 
    while (current != NULL) { 
        while (current->next != NULL && prev->next->data == current->next->data){
            current = current->next;
        }
        if (prev->next == current) prev = prev->next;
        else prev->next = current->next; 

        current = current->next;
    }
    head = dummy->next;
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
    head=removeAllDuplicates(head);
    print(head);
}