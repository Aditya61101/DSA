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

int heightOfBT(Node *curr){
    if (curr==NULL){
        return 0;
    }
    int leftHeight=heightOfBT(curr->left);
    int rightHeight=heightOfBT(curr->right);
    int height=1+max(leftHeight,rightHeight);
    return height;
}
int maxVal=-1e9;
int diameter(Node *curr){
    if (curr==NULL){
        return 0;
    }
    int leftH=heightOfBT(curr->left);
    int rightH=heightOfBT(curr->right);
    maxVal=max(maxVal,leftH+rightH);
    int left=diameter(curr->left);
    int right=diameter(curr->right);
    return maxVal;
}
int main(){
    Node *root=new Node(1);
    Node *lChild=new Node(2);
    Node *rChild=new Node(3);
    root->left=lChild;
    root->right=rChild;
    Node *nNode=new Node(5);
    lChild->right=nNode;
    int result=diameter(root);
    cout<<result;
}
// longest connection of 2 nodes.
//longest path between 2 nodes, path need not to pass through the root node.
//naive solution is to find the left_height and the right_height from every node and sum them up.