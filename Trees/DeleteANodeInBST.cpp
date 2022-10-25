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

// There are multiple ways we can restruct the BST after deleing the node.
// Time Complexity: O(Log2N) or height of a BST.
// Space Complexity: O(1) we are not using extra space.

Node* findLast(Node* root){
    while(root->right!=NULL)
        root=root->right;
    return root;
}

Node* helper(Node* root){
    if(root->left==NULL)
        return root->right;
   else if(root->right==NULL)
        return root->left;
    Node* rightNode=root->right;
    Node*lastLeft=findLast(root->left);
    lastLeft->right=root->right;
    return root->left;
}

Node* deleteNode(Node* root, int key) {
    if(root==NULL)
        return root;
    if(root->data==key){
        return helper(root);
    }
    Node* temp=root;
    while(root!=NULL){
        if(root->data>key){
            if(root->left!=NULL && root->left->data==key){
                root->left=helper(root->left);
                break;
            }
            else
                root=root->left;
        }
        else{
            if(root->right!=NULL && root->right->data==key){
                root->right=helper(root->right);
                break;
            }
            else
                root=root->right;
        }
    }
    return temp;
}

void dfs(Node* root){
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    dfs(root->right);
    dfs(root->left);
}

int main(){
    Node* root=newNode(4);
    root->left=newNode(2);
    root->right=newNode(6);
    root->left->left=newNode(1);
    root->left->right=newNode(3);
    root->right->left=newNode(5);
    root->right->right=newNode(7);
    Node* ans=deleteNode(root,7);
    dfs(root);
    return 0;
}