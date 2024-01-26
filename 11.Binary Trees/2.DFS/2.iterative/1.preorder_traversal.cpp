#include<bits/stdc++.h>
#include<stack>
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
void preOrder(Node *root){
    stack<Node*>s;
    s.push(root);
    while (!s.empty()){
        Node *node=s.top();
        s.pop();
        cout<<node->data<<" ";
        if (node->right!=NULL){
            s.push(node->right);
        }
        if (node->left!=NULL){
            s.push(node->left);
        }
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
    preOrder(root);
}