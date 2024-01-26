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
void print(vector<int>&result){
    for (auto &e : result){
        cout<<e<<" ";
    }
}
vector<int> postOrder(Node *root){
    stack<Node*>s;
    vector<int>postOrder;
    if (root==NULL){
        return postOrder;
    }
    Node *curr=root,*temp;
    while(curr!=NULL||!s.empty()){
        if (curr!=NULL){
            s.push(curr);
            curr=curr->left;   
        }
        else{
            temp=s.top()->right;
            if (temp==NULL){
                temp=s.top();
                s.pop();
                postOrder.push_back(temp->data);
                while(!s.empty()&&temp==s.top()->right){
                    temp=s.top();
                    s.pop();
                    postOrder.push_back(temp->data);
                }
            }
            else{
                curr=temp;
            }
        }
    }
    return postOrder;
}
int main(){
    Node *root=new Node(1);
    Node *lChild=new Node(2);
    Node *rChild=new Node(3);
    root->left=lChild;
    root->right=rChild;
    Node *nNode=new Node(5);
    lChild->right=nNode;
    vector<int>result=postOrder(root);
    print(result);
}