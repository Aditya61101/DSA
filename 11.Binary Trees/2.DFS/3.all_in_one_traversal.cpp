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
void allInOneTraversal(Node *root){
    vector<int>postOrder;
    vector<int>inOrder;
    vector<int>preOrder;
    if (root==NULL){
        return;
    }
    stack<pair<Node*,int>>s;
    Node *curr=root;
    s.push({curr,1});
    while (!s.empty()){
        if(s.top().second==1){
            preOrder.push_back(s.top().first->data);
            pair<Node*,int>temp=s.top();
            s.pop();
            temp.second++;
            s.push(temp);
            if(temp.first->left!=NULL){
                s.push({temp.first->left,1});           
            }
        }
        else if(s.top().second==2){
            inOrder.push_back(s.top().first->data);
            pair<Node*,int>temp=s.top();
            s.pop();
            temp.second++;
            s.push(temp);
            if (temp.first->right!=NULL){
                s.push({temp.first->right,1});                
            }
        }
        else if (s.top().second==3){
            postOrder.push_back(s.top().first->data);
            s.pop();
        }
    }
    cout<<"PreOrder: ";
    for (auto &e : preOrder){
        cout<<e<<" ";
    }
    cout<<"\nInOrder: ";
    for (auto &e : inOrder){
        cout<<e<<" ";
    }
    cout<<"\nPostOrder: ";
    for (auto &e : postOrder){
        cout<<e<<" ";
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
    allInOneTraversal(root);
}