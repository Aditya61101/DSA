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
vector<vector<int>> verticalTraversal(Node *root){
    queue<pair<Node*,pair<int,int>>>toDo;
    //vertical,level,nodes
    map<int,map<int,multiset<int>>>nodes;
    toDo.push({root,{0,0}});
    while(!toDo.empty()){
        auto p=toDo.front();
        toDo.pop();
        Node *curr=p.first;
        int x=p.second.first,y=p.second.second;
        nodes[x][y].insert(curr->data);
        if (curr->left!=NULL){
            toDo.push({curr->left,{x-1,y+1}});
        }
        if (curr->right!=NULL){
            toDo.push({curr->right,{x+1,y+1}});
        }
    }
    vector<vector<int>>ans;
    for (auto &p : nodes){
        vector<int>col;
        for (auto &q : p.second){
            col.insert(col.end(),q.second.begin(),q.second.end());
        }
        ans.push_back(col);
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
    vector<vector<int>>result=verticalTraversal(root);
    print(result);
}
//queue<pair<Node*,pair<int,int>>>toDo;=>{node,{x,y}}
