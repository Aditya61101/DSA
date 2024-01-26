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
void print(Node *root){
    if (root==NULL){
        return;
    }
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}
Node *deSerialize(string &data){
    if (data.length()==0){
        return NULL;
    }
    // to iterate data like an object we have used stringstream
    stringstream s(data);
    string str;
    getline(s,str,',');
    Node *root=new Node(stoi(str));
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node *curr=q.front();
        q.pop();
        //for left of the current node
        getline(s,str,',');
        if(str=="#"){
            curr->left=NULL;
        }
        else{
            Node *leftNode=new Node(stoi(str));
            curr->left=leftNode;
            q.push(leftNode);
        }
        //for right of the current node
        getline(s,str,',');
        if(str=="#"){
            curr->right=NULL;
        }
        else{
            Node *rightNode=new Node(stoi(str));
            curr->right=rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
string serialize(Node *root){
    if (root==NULL){
        return "";
    }
    queue<Node*>q;
    string s;
    q.push(root);
    while(!q.empty()){
        Node *curr=q.front();
        q.pop();
        if(curr==NULL){
            s.append("#,");
        }
        else{
            s.append(to_string(curr->data)+',');
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    s.pop_back();
    return s;
}
int main(){
    Node *root=new Node(1);
    Node *lChild=new Node(2);
    Node *rChild=new Node(3);
    root->left=lChild;
    root->right=rChild;
    Node *nNode3=new Node(4);
    rChild->left=nNode3;
    Node *nNode2=new Node(5);
    rChild->right=nNode2;
    string res=serialize(root);
    cout<<res<<"\n";
    Node *newRoot=deSerialize(res);
    print(newRoot);
}
//can be done using BFS traversal.
//using stringstream we can iterate over a string like an object.