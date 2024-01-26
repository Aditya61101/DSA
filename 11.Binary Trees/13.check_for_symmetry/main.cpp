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

bool preOrder(Node *n1,Node *n2){    
    if(n1==NULL||n2==NULL){
        return n1==n2;
    }
	if(n1->data==n2->data){
		bool res1=preOrder(n1->left,n2->right);
		bool res2=preOrder(n1->right,n2->left);
		return res1&res2;
	}
	else{
		return false;
	}
}
int main(){
    Node *root=new Node(1);
    Node *lChild=new Node(2);
    Node *rChild=new Node(2);
    root->left=lChild;
    root->right=rChild;
    Node *node1L=new Node(3);
    Node *node1R=new Node(4);
    Node *node2L=new Node(4);
    Node *node2R=new Node(3);
    lChild->left=node1L;
    lChild->right=node1R;
    rChild->left=node2L;
    rChild->right=node2R;
    cout<<preOrder(root->left,root->right);
}
//we start from the root->left and root->right.
//then for left we first go to left and then to right.
//for right we first go to right and then to left.
//we do this simultaneously and check if the node values are same or not.