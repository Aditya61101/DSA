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

void print(Node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}
Node* findLastRight(Node *root){
    if (root->right==NULL){
        return root;
    }
    return findLastRight(root->right);
}
Node* helper(Node *root){
    if (root->left==NULL){
        return root->right;
    }
    else if(root->right==NULL){
        return root->left;
    }
    Node *rightChild=root->right;
    Node *lastRight=findLastRight(root->left);
    lastRight->right=rightChild;
    return root->left;
}
Node* searchBST(Node *root,int x){
    if(root==NULL){
        return NULL;  
    }
    if(root->data==x){
        return helper(root);
    }
    Node *curr=root;
    while(curr){
        if(curr->data>x){
            if(curr->left&&curr->left->data==x){
                curr->left=helper(curr->left);
                break;
            }
            else{
                curr=curr->left;
            }
        }
        else{
            if(curr->right&&curr->right->data==x){
                curr->right=helper(curr->right);
                break;
            }
            else{
                curr=curr->right;
            }
        } 
    }
    return root;
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
    int req=5;
    print(root);
    searchBST(root,req);
    cout<<"\n";
    print(root);
}