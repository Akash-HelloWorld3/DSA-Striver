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

bool isIdentical(Node* root1,Node* root2){
    if(root1==NULL && root2==NULL)
        return true;
    if(root1==NULL || root2==NULL)
        return false;
    if(root1->data!=root2->data)
        return false;
    bool left=isIdentical(root1->left,root2->left);
    bool right=isIdentical(root1->right,root2->right);
    return left && right;
}


int main(){
    Node* root1= newNode(1);
    root1->left=newNode(2);
    root1->right=newNode(3);
    root1->left->left=newNode(4);
    root1->left->right=newNode(5);
    root1->right->left=newNode(6);
    root1->right->right=newNode(7);
    Node* root2= newNode(1);
    root2->left=newNode(2);
    root2->right=newNode(3);
    root2->left->left=newNode(4);
    root2->left->right=newNode(5);
    root2->right->left=newNode(6);
    root2->right->right=newNode(7);
    if(isIdentical(root1,root2))
        cout<<"It is a Identical Binary Tree ";
    else
        cout<<"It is not a Identical Binary Tree ";
    return 0;
}