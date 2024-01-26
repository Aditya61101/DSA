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

void print(vector<int>&res){
    for (auto &e:res){
        cout<<e<<" ";
    }
}
void markParents(Node *root,unordered_map<Node*,Node*>&mp){
    queue<Node*>q;
    q.push(root);
    while (!q.empty()){
        Node *curr=q.front();
        q.pop();
        if(curr->left){
            //making connection
            mp[curr->left]=curr;
            q.push(curr->left);
        }
        if(curr->right){
            //making connection
            mp[curr->right]=curr;
            q.push(curr->right);
        }
    }
}
vector<int> kDistance(Node *root,Node *tar,int k){
    unordered_map<Node*,Node*>parent_track;
    markParents(root,parent_track);
    unordered_map<Node*,bool>visited;
    queue<Node*>q;
    q.push(tar);
    visited[tar]=true;
    int cur_lvl=0;
    //bfs traversal
    while(true){
        int size=q.size();
        if (cur_lvl==k){
            break;
        }
        cur_lvl++;
        for(int i=0; i<size; i++){
            Node *curr=q.front();
            q.pop();
            //visiting left node
            if(curr->left&&visited[curr->left]==false){
              q.push(curr->left);
              visited[curr->left]=true;
            }
            //visiting right node
            if(curr->right&&!visited[curr->right]){
              q.push(curr->right);
              visited[curr->right]=true;
            }
            //visiting parent node
            if (parent_track[curr]&&!visited[parent_track[curr]]){
                q.push(parent_track[curr]);
                visited[parent_track[curr]]=true;
            }
        }
    }
    vector<int>res;
    while (!q.empty()){
        Node *curr=q.front();
        q.pop();
        res.push_back(curr->data);
    }
    return res;
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
    int k=2;
    vector<int>result=kDistance(root,rChild,k);
    print(result);
}
//algorithm approach:-
// create a hashmap which connects child to its parent in other direction as well.
//keep moving by 1 distance upward, leftward, rightward from a node.
//T.C: O(N)+O(N)=O(N), S.C: O(N)+O(N)=O(N)