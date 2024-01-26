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
class NodeValue{
    public:
        int maxNode,minNode,maxSize;
    NodeValue(int minN,int maxN,int maxS){
        this->minNode=minN;
        this->maxNode=maxN;
        this->maxSize=maxS;
    }
};
class Solution{
    private:
        NodeValue larBSTsubTreeHelper(Node *root){
            if(!root){
            return NodeValue(INT_MAX,INT_MIN,0);  
            }
            auto left=larBSTsubTreeHelper(root->left);
            auto right=larBSTsubTreeHelper(root->right);
            if(left.maxNode<root->data&&root->data<right.minNode){
                /* it is a BST */
                return NodeValue(min(root->data,left.minNode),max(root->data,right.maxNode),left.maxSize+right.maxSize+1);
            }
            //not a BST
            return NodeValue(INT_MIN,INT_MAX,max(left.maxSize,right.maxSize));
        }
    public:
        int largestBSTSubTree(Node* root){
            return larBSTsubTreeHelper(root).maxSize;
        }
};
int main(){
    Node* root=new Node(8);
    Node* lChild=new Node(5);
    Node* rChild=new Node(12);
    Node* node1=new Node(4);
    Node* node2=new Node(7);
    Node* node3=new Node(10);
    Node* node4=new Node(14);
    Node* node5=new Node(6);
    Node* node6=new Node(13);
    root->left=lChild;
    root->right=rChild;
    lChild->left=node1;
    lChild->right=node2;
    rChild->left=node3;
    rChild->right=node4;
    node4->left=node6;
    node2->left=node5;
}
//if not BST , size=max(left.size,right.size), max=INT_MAX,min=INT_MIN
//if BST, size=left.size+right.size+1, max=max(curr,right), min=min(curr,left)