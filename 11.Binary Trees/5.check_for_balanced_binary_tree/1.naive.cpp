//balanced b.t means for every node abs(height(left)-height(right))<=1
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

int heightOfBT(Node *curr){
    if(curr==NULL){
        return 0;
    }
    int leftHeight=heightOfBT(curr->left);
    int rightHeight=heightOfBT(curr->right);
    int height=1+max(leftHeight,rightHeight);
    return height;
}
bool check(Node *curr){
    if (curr==NULL){
        return true;
    }
    int leftH=heightOfBT(curr->left);
    int rightH=heightOfBT(curr->right);
    if (abs(rightH-leftH)>1){
        return false;
    }
    bool left=check(curr->left);
    bool right=check(curr->right);
    //return left&&right;
    if (!left||!right){
        return false;
    }
    return true;
}
int main(){
    Node *root=new Node(1);
    Node *lChild=new Node(2);
    Node *rChild=new Node(3);
    root->left=lChild;
    root->right=rChild;
    Node *nNode=new Node(5);
    lChild->right=nNode;
    bool result=check(root);
    cout<<result;
}