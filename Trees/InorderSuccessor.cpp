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

Node* inorderSuccessor(Node* root,Node* x){
    if(root==NULL)
        return NULL;
    Node* successor=NULL;
    while(root){
        if(root->data <= x->data)
            root=root->right;
        else{
            successor=root;
            root=root->left;
        }
    }
    return successor;
}

int main(){
    Node* root=newNode(4);
    root->left=newNode(2);
    root->right=newNode(6);
    root->left->left=newNode(1);
    root->left->right=newNode(3);
    root->right->left=newNode(5);
    root->right->right=newNode(7);
    Node* ans=inorderSuccessor(root,root->right->left);
    if(ans)
        cout<<"The Inorder Successor of the Node "<<root->right->left->data<<" : "<<ans->data<<"."<<endl;
    else
        cout<<"There is no Inorder Successor for the Node "<<root->right->left->data<<"."<<endl;
    return 0;
}