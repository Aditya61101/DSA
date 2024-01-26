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

bool isIdentical(Node *n1,Node *n2){    
    if (n1==NULL||n2==NULL){
        return n1==n2;
    }
	if(n1->data==n2->data){
		bool res1=isIdentical(n1->left,n2->left);
		bool res2=isIdentical(n1->right,n2->right);
		return res1&res2;
	}
	return false;
}
int main(){
    Node *root=new Node(10);
    Node *lChild=new Node(9);
    Node *rChild=new Node(20);
    root->left=lChild;
    root->right=rChild;
    Node *nNode=new Node(15);
    rChild->left=nNode;
    Node *nNode1=new Node(7);
    rChild->right=nNode1;

    Node *root1=new Node(10);
    Node *lChild1=new Node(9);
    Node *rChild1=new Node(20);
    root1->left=lChild1;
    root1->right=rChild1;
    Node *nNode2=new Node(15);
    rChild1->left=nNode2;
    // Node *nNode3=new Node(7);
    // rChild1->right=nNode3;
    cout<<isIdentical(root,root1);
}


// if(n1==NULL&&n2!=NULL||n2==NULL&&n1!=NULL){
	// 	return false;
	// }
    // else if(n1==NULL&&n2==NULL){
    //     return true;
// }