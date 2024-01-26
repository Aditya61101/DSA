#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node *left,*right;
    int data;
    Node(int x){
        data=x;
        left=right=NULL;
    }
};
Node* findLCA(Node *root,Node *n1,Node *n2){
    if(root==NULL){
        return NULL;  
    }
    Node *curr=root;
    while(curr){
        //if both of them are on the left
        if(curr->data>n1->data&&curr->data>n2->data){
            curr=curr->left;
        }
        //if both of them are on the right
        else if(curr->data<n1->data&&curr->data<n2->data){
            curr=curr->right;
        }
        else{
            return curr;
        }
    }
}
int main(){
    Node* root=new Node(8);
    Node* lChild=new Node(5);
    Node* rChild=new Node(12);
    Node* node1=new Node(4);
    Node* node2=new Node(7);
    Node* node3=new Node(10);
    Node* node4=new Node(14);
    Node* node5=new Node(6);
    Node* node6=new Node(13);
    root->left=lChild;
    root->right=rChild;
    lChild->left=node1;
    lChild->right=node2;
    rChild->left=node3;
    rChild->right=node4;
    node4->left=node6;
    node2->left=node5;
    Node *curr=findLCA(root,node1,node4);
    cout<<curr->data;
}