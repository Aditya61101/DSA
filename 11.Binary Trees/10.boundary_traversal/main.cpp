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
void addLeft(Node *root,vector<int>&v){
    Node *curr=root->left;
    while(curr){
        if(curr->left!=NULL||curr->right!=NULL)
            v.push_back(curr->data);
        if(curr->left!=NULL)
            curr=curr->left;
        else
            curr=curr->right;
    }
}
void addLeaves(Node *root,vector<int>&v){
    if (root==NULL)
        return;
    //the node is the leaf node
    if (root->left==NULL&&root->right==NULL){
        v.push_back(root->data);
        return;
    }
    addLeaves(root->left,v);
    addLeaves(root->right,v);
}
void addRight(Node *root,vector<int>&v){
    Node *curr=root->right;
    vector<int>ans;
    while(curr){
        if(curr->left!=NULL||curr->right!=NULL)
            ans.push_back(curr->data);
        if(curr->right!=NULL)
            curr=curr->right;
        else
            curr=curr->left;
    }
    for(int i=0;i<(int)ans.size();i++){
        v.push_back(ans[ans.size()-i-1]);
    }
}
int main(){
    Node *root=new Node(1);
    Node *lChild=new Node(2);
    Node *rChild=new Node(3);
    root->left=lChild;
    root->right=rChild;
    Node *nNode1=new Node(6);
    rChild->right=nNode1;
    Node *nNode2=new Node(4);
    Node *nNode3=new Node(5);
    lChild->left=nNode2;
    lChild->right=nNode3;
    vector<int>res;
    res.push_back(root->data);
    addLeft(root,res);
    addLeaves(root,res);
    addRight(root,res);
    print(res);
}
//for anti-clockwise
//1.left_boundary_excluding leaf nodes.
//2.leaf nodes => inOrder traversal(l->ro->r)
//3.right boundary in the reverse order excluding leaf nodes.