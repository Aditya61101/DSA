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
int main(){
    Node *root=new Node(1);
    Node *lChild=new Node(2);
    Node *rChild=new Node(3);
    root->left=lChild;
    root->right=rChild;
    Node *nNode=new Node(5);
    lChild->right=nNode;
    int result=heightOfBT(root);
    cout<<result;
}