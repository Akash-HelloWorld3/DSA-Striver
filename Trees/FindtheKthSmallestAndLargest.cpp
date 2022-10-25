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

int kthLarge(Node* root,int &k){
    if(root==NULL)
        return -1;
    int right=kthLarge(root->right,k);
    if(right!=-1)
        return right;
    if(--k==0)
        return root->data;
    int left=kthLarge(root->left,k);
    return left;
}

// Time Complexity: O(N).
// Space Complexity: O(1) we are not using extra space.

int kthSmall(Node* root,int &k){
    if(root==NULL)
        return -1;
    int left=kthSmall(root->left,k);
    if(left!=-1)
        return left;
    if(--k==0)
        return root->data;
    int right=kthSmall(root->right,k);
    return right;
}

int main(){
    Node* root=newNode(4);
    root->left=newNode(2);
    root->right=newNode(6);
    root->left->left=newNode(1);
    root->left->right=newNode(3);
    root->right->left=newNode(5);
    root->right->right=newNode(7);
    int k=3;
    int large=kthLarge(root,k);
    int kk=3;
    int small=kthSmall(root,kk);
    if(large==-1)
        cout<<"There is no Kth Largest node present."<<endl;
    else
        cout<<"The Kth Largest Node: "<<large<<endl;
    if(small==-1)
        cout<<"There is no Kth Smallest node present."<<endl;
    else
        cout<<"The Kth Smallest Node: "<<small<<endl;
    return 0;
}