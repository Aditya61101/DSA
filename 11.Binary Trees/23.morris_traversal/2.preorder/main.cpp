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
vector<int> getPreOrder(Node *root){
    vector<int>preOrder;
    Node *curr=root;
    while(curr!=NULL){
        if(!curr->left){
            preOrder.push_back(curr->data);
            curr=curr->right;  
        }
        else{
            Node *prevC=curr->left;
            while(prevC->right&&prevC->right!=curr){
                prevC=prevC->right;
            }
            if (prevC->right==NULL){
                prevC->right=curr;
                preOrder.push_back(curr->data);
                curr=curr->left;
            }
            else{
                prevC->right=NULL;
                curr=curr->right;
            }
        }
    }
    return preOrder;
}
int main(){
    Node *root=new Node(1);
    Node *lChild=new Node(2);
    Node *rChild=new Node(3);
    root->left=lChild;
    root->right=rChild;
    Node *nNode=new Node(5);
    lChild->right=nNode;
    vector<int>result=getPreOrder(root);
    print(result);
}
//T.C: O(N), S.C: O(1)
//Uses threaded binary tree
//if left==NULL -> print(curr) and then move(curr->right)
//else point rightmost node on left subtree to the root node.
//check if their is a pointer in previous fashion if it exists then remove that pointer and then move curr->right.