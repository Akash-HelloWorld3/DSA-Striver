#include<iostream>
#include<vector>
using namespace std;

typedef struct Node{
    int data;
    Node* left;
    Node* right;
}Node;

Node* newNode(int val){
    Node* node=(Node*)malloc(sizeof(Node));
    node->data=val;
    node->left=node->right=NULL;
    return node;
}

// Time Complexity: O(N) because we are visiting N nodes.
// Space Complexity: O(N) if all the node are present in the last level, then the queue would approximately contain O(N) Space.

void dfsLeft(Node* root,vector<int>&left){
    if(root==NULL || (root->left==NULL && root->right==NULL))
        return;
    left.push_back(root->data);
    if(root->left!=NULL)
        dfsLeft(root->left,left);
    else if(root->right!=NULL)
        dfsLeft(root->right,left);
    return;
}

void dfsLeaf(Node* root,vector<int>&leaf){
    if(root==NULL)
        return;
    if(root->left==NULL && root->right==NULL){
        leaf.push_back(root->data);
        return;
    }
    dfsLeaf(root->left,leaf);
    dfsLeaf(root->right,leaf);
    return;
}

void dfsRight(Node* root,vector<int>&right){
    if(root==NULL || (root->left==NULL && root->right==NULL))
        return;
    right.push_back(root->data);
    if(root->right!=NULL)
        dfsLeft(root->right,right);
    else if(root->left!=NULL)
        dfsLeft(root->left,right);
    return;
}

vector<int> boundaryTraversal(Node* root){
    vector<int>left,leaf,right;
    if(root==NULL)
        return left;
    if(root->left!=NULL || root->right!=NULL)
        left.push_back(root->data);
    dfsLeft(root->left,left);
    dfsLeaf(root,leaf);
    dfsRight(root->right,right);
    for(auto it:leaf)
        left.push_back(it);
    for(int i=right.size()-1;i>=0;i--)
        left.push_back(right[i]);
    return left;
}


int main(){
    Node* root= newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    root->right->right=newNode(7);
    vector<int>ans=boundaryTraversal(root);
    for(auto it:ans)
        cout<<it<<" ";
    cout<<endl;
    return 0;
}