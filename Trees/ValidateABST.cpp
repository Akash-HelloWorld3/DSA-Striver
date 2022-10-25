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
// Space Complexity: O(1) we are not using extra space.

int isValidBST(Node* root,long lr,long rr){
    if(root==NULL)
        return true;
    if(root->data > rr || root->data <lr)
        return false;
    int left=isValidBST(root->left,lr,root->data);
    int right=isValidBST(root->right,root->data,rr);
    return left && right;
}

int main(){
    Node* root=newNode(4);
    root->left=newNode(2);
    root->right=newNode(6);
    root->left->left=newNode(1);
    root->left->right=newNode(3);
    root->right->left=newNode(5);
    root->right->right=newNode(7);
    if(isValidBST(root,LONG_MIN,LONG_MAX))
        cout<<"It is a Binary Search Tree."<<endl;
    else
        cout<<"It is not a Binary Search Tree."<<endl;
    return 0;
}