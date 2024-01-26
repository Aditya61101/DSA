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
Node *first,*middle,*last,*prevN;
void inOrder(Node *root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    if(prevN!=NULL&&(root->data<prevN->data)){
        //if this is first violation, mark these two nodes as first and middle
        if(!first){
          first=prevN;
          middle=root;  
        }
        //if this is second violation, mark this node as last
        else{
            last=root;
        }
    }
    //mark this node as previous
    prevN=root;
    inOrder(root->right);
}
Node* recoverTree(Node *root){
    first=middle=last=NULL;
    prevN=new Node(INT_MIN);
    inOrder(root);
    if(first&&last){
      swap(first->data,last->data);
    }
    else if(first&&middle){
      swap(first->data,middle->data);
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
    recoverTree(root);
}
//t.c:O(n),s.c:O(1)