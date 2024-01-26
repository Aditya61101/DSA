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

int LCA(Node *root,Node *n1,Node *n2){
    if (root==NULL){
        return NULL;
    }
    if (root->data!=n1->data&&root->data!=n2->data){
        // finding LCA in left subtree
        int res1=LCA(root->left,n1,n2);
        // finding LCA in right subtree
        int res2=LCA(root->right,n1,n2);
        if(res1!=NULL&&res2!=NULL){
            return root->data;
        }
        return res1|res2;
    }
    else{
        return root->data;
    }
}
int main(){
    Node *root=new Node(1);
    Node *lChild=new Node(2);
    Node *rChild=new Node(3);
    root->left=lChild;
    root->right=rChild;
    Node *nNode=new Node(4);
    lChild->left=nNode;
    Node *nNode1=new Node(5);
    lChild->right=nNode1;
    Node *nNode3=new Node(6);
    nNode1->left=nNode3;
    Node *nNode2=new Node(7);
    rChild->right=nNode2;
    int result=LCA(root,nNode,nNode1);
    cout<<result;
}
//brute force approach:-
//find all elements from root to node1 and then root to node2 then the one which matches at the end will be the LCA.
//optimal solution: -
//use DFS.
// if we found NULL then we return it, else if found that node which we require we return it. If for a node, we are returning non NULL values from both the sides, this means that node is the LCA.