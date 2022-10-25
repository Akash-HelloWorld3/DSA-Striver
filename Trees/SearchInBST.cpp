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

// Time Complexity: O(Log2N) or height of a BST.
// Space Complexity: O(Log2N) or height of a BST (auxilary stack space).

Node* findNodeBST(Node* root,int target){
    if(root!=NULL && root->data==target)
        return root;
    if(root==NULL)
        return NULL;
    if(target<=root->data)
        return findNodeBST(root->left,target);
    else
        return findNodeBST(root->right,target);
}

// Time Complexity: O(Log2N) or height of a BST.
// Space Complexity: O(1) we are not using extra space.

Node* findNodeBST1(Node* root,int target){
    while(root!=NULL && root->data!=target){
        root= root->data<=target? root->left:root->right;
    }
    return root;
}

int main(){
    Node* root=newNode(4);
    root->left=newNode(2);
    root->right=newNode(6);
    root->left->left=newNode(1);
    root->left->right=newNode(3);
    root->right->left=newNode(5);
    root->right->right=newNode(7);
    Node* ans=findNodeBST(root,7);
    // Node* ans=findNodeBST1(root,7);
    if(ans!=NULL)
        cout<<"Found the Node: "<<ans->data<<endl;
    else
        cout<<"The Node does not exit"<<endl;
    return 0;
}