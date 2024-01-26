#include<bits/stdc++.h>
#include<stack>
#include<vector>
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
vector<int> postOrder(Node *root){
    stack<Node*>s1,s2;
    vector<int>postOrder;
    if (root==NULL){
        return postOrder;
    }
    s1.push(root);
    while (!s1.empty()){
        root=s1.top();
        s1.pop();
        s2.push(root);
        if (root->left!=NULL){
            s1.push(root->left);
        }
        if (root->right!=NULL){
            s1.push(root->right);
        }
    }
    while (!s2.empty()){
        postOrder.push_back(s2.top()->data);
        s2.pop();
    }
    return postOrder;
}
int main(){
    Node *root=new Node(1);
    Node *lChild=new Node(2);
    Node *rChild=new Node(3);
    root->left=lChild;
    root->right=rChild;
    Node *nNode=new Node(5);
    lChild->right=nNode;
    vector<int>result=postOrder(root);
    print(result);
}