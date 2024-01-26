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
void print(Node *root){
    if (root==NULL){
        return;
    }
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}
Node *buildTree(vector<int>&preO,int pS,int pE,vector<int>&inO,int iS,int iE,map<int,int>&mp){
    if (pS>pE||iS>iE){
        return NULL;
    }
    Node *root=new Node(preO[pS]);
    //below line finds, the index in inOrder list
    int inRoot=mp[root->data];
    int numLeft=inRoot-iS;
    root->left=buildTree(preO,pS+1,pS+numLeft,inO,iS,inRoot-1,mp);
    root->right=buildTree(preO,pS+numLeft+1,pE,inO,inRoot+1,iE,mp);
    return root;
}
Node *createMap(vector<int>&preO,vector<int>&inO){
    map<int,int>mp;
    for (int i = 0; i <inO.size(); i++){
        mp[inO[i]]=i;
    }
    Node *root=buildTree(preO,0,preO.size()-1,inO,0,inO.size()-1,mp);
    return root;   
}
int main(){
    vector<int>inOrder={40,20,50,10,60,30};
    vector<int>preOrder={10,20,40,50,30,60};
    Node *root=createMap(preOrder,inOrder);
    print(root);
}
//preorder's first element is always the main root of the binary tree.