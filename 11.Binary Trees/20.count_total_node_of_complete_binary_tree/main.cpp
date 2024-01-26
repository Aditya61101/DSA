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

int findLH(Node *root){
    int h=0;
    while(root){
        h++;
        root=root->left;
    }
    return h;
}
int findRH(Node *root){
    int h=0;
    while(root){
        h++;
        root=root->right;
    }
    return h;
}
int heightComp(Node *root){
    if (root==NULL){
        return 0;
    }
    int leftHeight=findLH(root);
    int rightHeight=findRH(root);
    //it means it is a full binary subtree
    if(leftHeight==rightHeight){
        return pow(2,leftHeight)-1;
    }
    int leftCall=heightComp(root->left);
    int rightCall=heightComp(root->right);
    return 1+leftCall+rightCall;
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
    rChild->left=nNode3;
    Node *nNode2=new Node(7);
    rChild->right=nNode2;
    int result=heightComp(root);
    cout<<result;
}
//T.C: O(logN)^2, S.C:O(logN)