#include<iostream>
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

// Time Complexity: O(N).
// Space Complexity: O(N).

Node* prev=NULL;

void flatten(Node* root){
    if(root==NULL)
        return;
    flatten(root->right);
    flatten(root->left);
    root->right=prev;
    root->left=NULL;
    prev=root;
    return;
}
void dfs(Node* root){
    if(root==NULL)
        return;
    dfs(root->left);
    cout<<root->data<<" ";
    dfs(root->right);
    return;
}

int main(){
    Node* root= newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    root->right->right=newNode(7);
    flatten(root);
    dfs(root);
    return 0;
}