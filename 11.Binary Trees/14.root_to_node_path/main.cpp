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
bool rootToNode(Node *root,int x,vector<int>&res){
    if(root==NULL){
        res.pop_back();
        return false;
    }
    if (root->data!=x){
        res.push_back(root->data);
        bool res1=rootToNode(root->left,x,res);
        bool res2=rootToNode(root->right,x,res);
        return res1|res2;
    }
    else{
        res.push_back(x);
        return true;
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
    vector<int>res;
    int x=6;
    rootToNode(root,x,res);
    print(res);
}
//can be done using inOrder traversal.