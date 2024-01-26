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

void morrisTraversal(Node *root,int k){
    int count=0;
    Node *curr=root;
    while(curr){
        if(!curr->left){
            count++;
            if(count==k){
                cout<<curr->data;
                return;
            }
            curr=curr->right;
        }
        else{
            Node *prevC=curr->left;
            while(prevC->right&&prevC->right!=curr){
                prevC=prevC->right;
            }
            if (prevC->right==NULL){
                prevC->right=curr;
                curr=curr->left;
            }
            else{
                prevC->right=NULL;
                count++;
                if(count==k){
                    cout<<curr->data;
                    return;
                }
                curr=curr->right;
            }
        }
    }
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
    int k=3;
    morrisTraversal(root,k);
}
//inOrder of any bst always gives elements in sorted order.