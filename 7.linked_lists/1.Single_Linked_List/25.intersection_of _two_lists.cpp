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
Node *head1=NULL;
Node *head2=NULL;

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
void findIntersection(Node *head1,Node *head2){
    Node *curr1=head1,*curr2=head2;
    int size1=0,size2=0;
    while (curr1!=NULL){
        size1++;
        curr1=curr1->next;
    }
    curr1=head1;
    while (curr2!=NULL){
        size2++;
        curr2=curr2->next;
    }
    curr2=head2;
    int times=abs(size2-size1);
    if (size1>size2){
        int count=0;
        while(count<times){
            curr1=curr1->next;
            count++;
        }
    }
    else if(size1<size2){
        int count=0;
        while(count<times){
            curr2=curr2->next;
            count++;
        }
    }
    while (curr1!=curr2){
        curr1=curr1->next;
        curr2=curr2->next;
    }
    cout<<curr1->data;
}
int main(){
    head1=new Node(17);
    Node *temp1=new Node(5);
    Node *temp2=new Node(8);
    Node *temp3=new Node(7);
    Node *temp4=new Node(10);
    Node *temp5=new Node(12);
    Node *temp6=new Node(15);
    head1->next=temp1;
    temp1->next=temp2;
    temp2->next=temp3;
    temp3->next=temp4;
    temp4->next=temp5;
    temp5->next=temp6;
    head2=new Node(9);
    head2->next=temp4;
    findIntersection(head1,head2);
}