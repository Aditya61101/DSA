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
vector<int> inOrderIterative(Node *root){
    stack<Node*>s;
    vector<int>inOrder;
    while(true){
        if(root!=NULL){
            s.push(root);
            root=root->left;
        }
        else{
            if (s.empty()){
                break;
            }
            root=s.top();
            s.pop();
            inOrder.push_back(root->data);
            root=root->right;
        }
    }
    return inOrder;
}
int main(){
    Node *root=new Node(1);
    Node *lChild=new Node(2);
    Node *rChild=new Node(3);
    root->left=lChild;
    root->right=rChild;
    Node *nNode=new Node(5);
    lChild->right=nNode;
    vector<int>result=inOrderIterative(root);
    print(result);
}