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
void print(vector<vector<int>>&result){
    for (auto &v : result){
        for (auto &e : v){
            cout<<e<<" ";
        }
    }
}
vector<vector<int>> BFS(Node *root){
    vector<vector<int>>ans;
    if (root==NULL){
        return ans;
    }
    queue<Node*>q;
    q.push(root);
    while (!q.empty()){
        int size=q.size();
        vector<int>level;
        for(int i=0; i<size; i++){
            Node *node=q.front();
            q.pop();
            if (node->left!=NULL){
                q.push(node->left);
            }
            if (node->right!=NULL){
                q.push(node->right);
            }
            level.push_back(node->data);
        }
        ans.push_back(level);
    }
    return ans;
}
int main(){
    Node *root=new Node(1);
    Node *lChild=new Node(2);
    Node *rChild=new Node(3);
    root->left=lChild;
    root->right=rChild;
    Node *nNode=new Node(5);
    lChild->right=nNode;
    vector<vector<int>>result=BFS(root);
    print(result);
}