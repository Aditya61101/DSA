#include<iostream>
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

void print(Node *head){
    if (head==NULL){
        return;
    }
    Node *temp=head;
    while (temp->next!=head){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    //for the last node
    cout<<temp->data;
    cout<<endl;
}
Node *insertAtBegin(int x, Node *head){
    Node *temp=new Node(x);
    if (head==NULL){
        temp->next=temp;
        return temp;
    }
    temp->next=head->next;
    head->next=temp;
    int tempData=temp->data;
    temp->data=head->data;
    head->data=tempData;
    return head;
}
int main(){
    Node *head=new Node(10);
    head->next=head;
    Node *Node2=new Node(20);
    head->next=Node2;
    Node2->next=head;
    Node *Node3=new Node(30);
    Node2->next=Node3;
    Node3->next=head;
    print(head);
    int x=5;
    head=insertAtBegin(x,head);
    print(head);
}
//naive solution
//Node *curr=head;
// while (curr->next!=head){
//   curr=curr->next;
//}
//curr->next=temp;
//return temp;

//efficient solution(O(1))
//insert the node in b/w 1st and 2nd node and then swap the data b/w 1st and 2nd node.