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

int childSum(Node *root){
    if (root==NULL){
        return 0;
    }
    int child=0;
    if (root->left){
        child+=root->left->data;
    }
    if (root->right){
        child+=root->right->data;
    }
    if ((root->data)>child){
        if (root->left){
            root->left->data=root->data;
        }
        if (root->right){
            root->right->data=root->data;
        }
    }
    else{
        root->data=child;
    }
    childSum(root->left);
    childSum(root->right);
    int tot=0;
    if (root->left){
        tot+=root->left->data;
    }
    if (root->right){
        tot+=root->right->data;
    }
    //to check if the node is not a leaf node
    if (root->left||root->right){
        root->data=tot;
    }
}
int main(){
    Node *root=new Node(1);
    Node *lChild=new Node(2);
    Node *rChild=new Node(3);
    root->left=lChild;
    root->right=rChild;
    Node *nNode=new Node(5);
    lChild->right=nNode;
    int result=childSum(root);
    cout<<result;
}
//algorithm approach:-
// if the curNode data is greater than the sum of its children then we assign this value to both the children. else we assign the sum to the root.
//while coming back we assign the sum of the children to the curNode if the curNode is not a leaf node.
