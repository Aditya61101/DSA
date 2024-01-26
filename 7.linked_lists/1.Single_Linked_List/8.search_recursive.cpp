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
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int searchRecursive(int x,Node *head){
    
    //if the linked list is empty
    if(head==NULL)
        return -1;
    //base case
    if(head->data==x)
        return 1;

    int res=searchRecursive(x,head->next);

    //if node is not present in linked list
    if (res==-1)
        return -1;

    return (res+1);
}
int main(){
    head=new Node(10);
    Node *temp1=new Node(30);
    Node *temp2=new Node(50);
    head->next=temp1;
    temp1->next=temp2;
    int x=60;
    int pos=searchRecursive(x,head);
    cout<<pos;
}