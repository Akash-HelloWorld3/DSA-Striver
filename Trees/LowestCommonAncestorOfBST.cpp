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

// Time Complexity: O(H).
// Space Complexity: O(1) we are not using extra space.

Node* LCA(Node* root,Node* a,Node* b){
    if(root==NULL)
        return NULL;
    while(root){
        if(a->data < root->data && b->data < root->data)
            root=root->left;
        else if(a->data > root->data && b->data > root->data)
            root=root->right;
        else
            return root;
    }
    return NULL;
}

int main(){
    Node* root=newNode(4);
    root->left=newNode(2);
    root->right=newNode(6);
    root->left->left=newNode(1);
    root->left->right=newNode(3);
    root->right->left=newNode(5);
    root->right->right=newNode(7);
    Node* ans=LCA(root,root->right->left,root->right->right);
    if(ans)
        cout<<"The Lowest Common Ancestor of the Nodes "<<root->right->left->data<<" and "<<root->right->right->data<<" : "<<ans->data<<"."<<endl;
    else
        cout<<"There is no Common Ancestor for the Nodes "<<root->right->left->data<<" and "<<root->right->right->data<<"."<<endl;
    return 0;
}