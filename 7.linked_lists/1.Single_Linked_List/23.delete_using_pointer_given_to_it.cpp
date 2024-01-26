//assuming the node to be deleted is not the last node
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
void deleteGivenNode(Node *temp){
    //copying the data from next node node to previous nodes
    temp->data=temp->next->data;
    //creating a node to delete the required node
    Node *tempNext=temp->next;
    temp->next=temp->next->next;
    delete(tempNext);
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
    print(head);
    deleteGivenNode(temp3);
    print(head);
}
