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
Node* createBST(vector<int>&v,int i,long upperBound){
    if(i==v.size()||v[i]>upperBound){
      return NULL;  
    }
    Node *root=new Node(v[i]);
    root->left=createBST(v,i+1,root->data);
    root->right=createBST(v,i+1,upperBound);
    return root;
}
int main(){
    vector<int>preOrder={8,5,1,7,10,12};
    Node *root=createBST(preOrder,0,INT_MAX);
    print(root);
}