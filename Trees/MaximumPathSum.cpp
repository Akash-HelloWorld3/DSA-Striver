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

// Time Complexity: O(N) because we are visiting N nodes.
// Space Complexity: O(N) because in case of skew tree the auxilary stack space will be O(N) where N is the no of nodes.

int diameter(Node* root,int &maxi){
    if(root==NULL)
        return 0;
    int left=max(0,diameter(root->left,maxi));
    int right=max(0,diameter(root->right,maxi));
    maxi=max(maxi,root->data+left+right);
    return root->data+max(left,right);
}

int main(){
    Node* root= newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    root->right->right=newNode(7);
    int maxi=INT_MIN;
    diameter(root,maxi);
    cout<<maxi;
    return 0;
}