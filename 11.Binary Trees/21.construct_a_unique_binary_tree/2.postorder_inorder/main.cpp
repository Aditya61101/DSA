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
Node *buildTree(vector<int>&postO,int pS,int pE,vector<int>&inO,int iS,int iE,map<int,int>&mp){
    if (pS>pE||iS>iE){
        return NULL;
    }
    Node *root=new Node(postO[pE]);
    //below line finds, the index in inOrder list
    int inRoot=mp[root->data];
    int numLeft=inRoot-iS;
    root->left=buildTree(postO,pS,pS+numLeft-1,inO,iS,inRoot-1,mp);
    root->right=buildTree(postO,pS+numLeft,pE-1,inO,inRoot+1,iE,mp);
    return root;
}
Node *createMap(vector<int>&posO,vector<int>&inO){
    map<int,int>mp;
    for (int i = 0; i <inO.size(); i++){
        mp[inO[i]]=i;
    }
    Node *root=buildTree(posO,0,posO.size()-1,inO,0,inO.size()-1,mp);
    return root;   
}
int main(){
    vector<int>inOrder={40,20,50,10,60,30};
    vector<int>postOrder={40,50,20,60,30,10};
    Node *root=createMap(postOrder,inOrder);
    print(root);
}
//postOrder's last element is always the main root of the binary tree.