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

int maxWidth(Node *root){
    if (root==NULL){
        return 0;
    }
    queue<pair<Node*,int>>q;
    q.push({root,0});
    int ans=0;
    while(!q.empty()){
        int size=q.size();
        int minIndex=q.front().second;
        int first,last;
        for(int i=0; i<size; i++){
            //in order to avoid overflow we subtract cur_index with minIndex.
            int cur_id=q.front().second-minIndex;
            Node *curr=q.front().first;
            q.pop();
            if (i==0){
                first=cur_id;
            }
            if (i==size-1){
                last=cur_id;
            }
            if (curr->left!=NULL){
                q.push({curr->left,2*cur_id+1});
            }
            if (curr->right!=NULL){
                q.push({curr->right,2*cur_id+2});
            }
        }
        ans=max(ans,last-first+1);
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
    int result=maxWidth(root);
    cout<<result;
}
//width: no. of nodes in a level between any 2 nodes.
//indexing of nodes of a binary tree
//in 0 based indexing, if parent node index is 'i', then its left child index will be 2*i and right child index will be 2*i+1.
//in 1 based indexing, if parent node index is 'i', then its left child index will be 2*i+1 and right child index will be 2*i+2.
