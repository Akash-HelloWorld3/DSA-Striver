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

// Time Complexity: O(N) because we are visting all the nodes.
// Space Complexity: O(N) because in worst case if it is a skew tree, the auxilary space will be O(N).

int check(Node* root){
    if(root==NULL)
        return 0;
    int left=check(root->left);
    int right=check(root->right);
    if(left==-1 || right==-1)
        return -1;
    if(abs(left-right)>1)
        return -1;
    return 1+max(left,right);
}

int main(){
    Node* root= newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    root->right->right=newNode(7);
    if(check(root)!=-1)
        cout<<"Balanced Binary Tree.";
    else
        cout<<"Not a Balanced Binary Tree";
    return 0;
}