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

// Time Complexity: O(N)
// Space Complexity: O(N)

bool symmetricTree(Node* left,Node* right){
    if(left==NULL && right==NULL)
        return true;
    if(left==NULL || right==NULL)
        return false;
    if(left->data!=right->data)
        return false;
    bool left1=symmetricTree(left->left,right->right);
    bool right1=symmetricTree(left->right,right->left);
    return left1 && right1;
}

int main(){
    Node* root= newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    root->right->right=newNode(7);
    if(root==NULL || (symmetricTree(root->left,root->right)))
        cout<<"It is a Symmetric Tree.";
    else 
        cout<<"It is not a Symmetric Tree.";
    cout<<endl;
    return 0;
}