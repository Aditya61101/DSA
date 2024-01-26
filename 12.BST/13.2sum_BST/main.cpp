#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node *left,*right;
    int data;
    Node(int x){
        data=x;
        left=right=NULL;
    }
};
stack<Node*>s;
bool isReverse=true;
bool hasNext(){
    return !s.empty();
}
void pushAll(Node *curr){
    for (;curr!=NULL;){
        s.push(curr);
        if(isReverse){
            curr=curr->right;
        }
        else{
            curr=curr->left;
        }
    }
}
int next(){
    Node* temp=s.top();
    s.pop();
    if(!isReverse){
      pushAll(temp->right);  
    }
    else{
        pushAll(temp->left);
    }
    return temp->data;
}
int main(){
    Node* root=new Node(8);
    Node* lChild=new Node(5);
    Node* rChild=new Node(12);
    Node* node1=new Node(4);
    Node* node2=new Node(7);
    Node* node3=new Node(10);
    Node* node4=new Node(14);
    Node* node5=new Node(6);
    Node* node6=new Node(13);
    root->left=lChild;
    root->right=rChild;
    lChild->left=node1;
    lChild->right=node2;
    rChild->left=node3;
    rChild->right=node4;
    node4->left=node6;
    node2->left=node5;
    s.push(root);  
}