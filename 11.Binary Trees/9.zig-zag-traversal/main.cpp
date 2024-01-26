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
vector<vector<int>>zigZagTraversal(Node *root){
    vector<vector<int>>ans;
    if (root==NULL){
        return ans;
    }
    queue<Node*>q;
    q.push(root);
    int flag=0;
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
        if (!flag){
            ans.push_back(level);
        }
        else{
            reverse(level.begin(),level.end());
            ans.push_back(level);
        }
        flag=!flag;
    }
    return ans;
}
int main(){
    Node *root=new Node(1);
    Node *lChild=new Node(2);
    Node *rChild=new Node(3);
    root->left=lChild;
    root->right=rChild;
    Node *nNode1=new Node(6);
    rChild->right=nNode1;
    Node *nNode2=new Node(4);
    Node *nNode3=new Node(5);
    lChild->left=nNode2;
    lChild->right=nNode3;
    vector<vector<int>>result=zigZagTraversal(root);
    print(result);
}