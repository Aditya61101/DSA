//re-arrange the binary tree into a linked list wrt to its preOrder traversal
//traversal should right->left->root
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
void flatTree(Node *root){
    Node *curr=root;
    while(curr){
        if(curr->left){
            Node *prev=curr->left;
            while(prev->right){
            prev=prev->right;
            }
            prev->right=curr->right;
            curr->right=curr->left;
        }
        curr=curr->right;
    }
}
int main(){
    Node *root=new Node(1);
    Node *lChild=new Node(2);
    Node *rChild=new Node(5);
    Node *node1=new Node(3);
    Node *node2=new Node(4);
    Node *node3=new Node(6);
    Node *node4=new Node(7);
    root->left=lChild;
    root->right=rChild;
    lChild->left=node1;
    lChild->right=node2;
    rChild->right=node3;
    node3->left=node4;
    flatTree(root);
}
//T.C:O(N),S.C:O(1)