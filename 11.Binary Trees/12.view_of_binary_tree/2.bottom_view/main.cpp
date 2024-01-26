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
vector<int> verticalTraversal(Node *root){
    queue<pair<Node*,int>>toDo;
    map<int,int>nodes;
    toDo.push({root,0});
    while(!toDo.empty()){
        auto p=toDo.front();
        toDo.pop();
        Node *curr=p.first;
        int x=p.second;
        nodes[x]=curr->data;
        if (curr->left!=NULL){
            toDo.push({curr->left,x-1});
        }
        if (curr->right!=NULL){
            toDo.push({curr->right,x+1});
        }
    }
    vector<int>ans;
    for (auto &p:nodes){
        ans.push_back(p.second);
    }
    return ans;
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
    nNode1->left=nNode3;
    Node *nNode2=new Node(7);
    rChild->right=nNode2;
    vector<int>result=verticalTraversal(root);
    print(result);
}
//can be done using vertical traversal.
//in this case we will only go one level deep for a particular column as we only want the first node of each column.