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
void print(vector<int>&result){
    for (auto &e : result){
        cout<<e<<" ";
    }
}
void reversePreOrder(Node *root, int level,vector<int>&res){
    if (root==NULL){
        return;
    }
    if (level==res.size()){
        res.push_back(root->data);
    }
    reversePreOrder(root->right,level+1,res);
    reversePreOrder(root->left,level+1,res);
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
    vector<int>res;
    reversePreOrder(root,0,res);
    print(res);
}
//can be done using reversePreOrder traversal.
//root->right->left
//if we come at a level for the first time then only we will insert that into the vector.
