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
int maxPathSum(Node *node,int &maxVal){
    if(node==NULL)
        return 0;
    
    //to avoid negative sum, we take max(0,recursion)
    int leftSum=max(0,maxPathSum(node->left,maxVal));
    int rightSum=max(0,maxPathSum(node->right,maxVal));
    // stores the maximum is stored
    maxVal=max(maxVal,node->data+leftSum+rightSum);
    //returns the maximum sum that can be extended from the current node
    return node->data+max(leftSum,rightSum);
}
int main(){
    Node *root=new Node(-10);
    Node *lChild=new Node(9);
    Node *rChild=new Node(20);
    root->left=lChild;
    root->right=rChild;
    Node *nNode=new Node(15);
    rChild->left=nNode;
    Node *nNode1=new Node(7);
    rChild->right=nNode1;
    int maxVal=INT_MIN;
    maxPathSum(root,maxVal);
    cout<<maxVal;
}
//leftSUM: stores the node values of the left nodes.
//rightSUM: stores the node values of the right nodes.