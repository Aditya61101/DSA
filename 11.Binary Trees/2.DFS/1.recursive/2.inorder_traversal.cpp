#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int x){
        data=x;
        left=right=NULL;
    }
};
void print(int val){
    cout<<val<<" ";
}
void inOrder(Node *node){
    if (node==NULL){
        return;
    }
    inOrder(node->left);
    print(node->data);
    inOrder(node->right);
}
int main(){
    Node *root=new Node(1);
    Node *lChild=new Node(2);
    Node *rChild=new Node(3);
    root->left=lChild;
    root->right=rChild;
    Node *nNode=new Node(5);
    lChild->right=nNode;
    inOrder(root);
}