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

// Time Complexity: O(N) because we are visiting every node.
// Space Complexity: O(N) (Auxilary stack space will be height of the binary tree) because in worst case if it is a skew tree
//                         the auxilary stack space will be O(N) due to N nodes.

void inorderTraversal(Node* root)
{
    if(root==NULL)
        return;
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

// Time Complexity: O(N) because we are visiting every node.
// Space Complexity: O(N) (Auxilary stack space will be height of the binary tree) because in worst case if it is a skew tree
//                         the auxilary stack space will be O(N) due to N nodes.

void preorderTraversal(Node* root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Time Complexity: O(N) because we are visiting every node.
// Space Complexity: O(N) (Auxilary stack space will be height of the binary tree) because in worst case if it is a skew tree
//                         the auxilary stack space will be O(N) due to N nodes.

void postorderTraversal(Node* root)
{
    if(root==NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<" ";
}

int main(){
    Node* root= newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    root->right->right=newNode(7);
    cout<<"Preorder Traversal: ";
    preorderTraversal(root);
    cout<<endl;
    cout<<"Inorder Traversal: ";
    inorderTraversal(root);
    cout<<endl;
    cout<<"Postorder Traversal: ";
    postorderTraversal(root);
    cout<<endl;
    return 0;
}