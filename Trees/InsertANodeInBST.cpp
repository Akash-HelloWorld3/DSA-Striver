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

// There are multiple places we can insert a new value. Instead of complicating we are inserting in the new value in a leaf node.
// Time Complexity: O(Log2N) or height of a BST.
// Space Complexity: O(1) we are not using extra space.

void insertNode(Node* root,int val){
    Node* node=newNode(val);
    if(root==NULL){
        root=node;
        return;
    }
    while(root){
        if(val<root->data){
            if(root->left)
                root=root->left;
            else{
                root->left=node;
                break;
            }
        }  
        else{
            if(root->right)
                root=root->right;
            else{
                root->right=node;
                break;
            }
        }    
    }
    return;
}

void dfs(Node* root,int target){
    if(root!=NULL && root->data==target){
        cout<<root->data<<endl;
        return;
    }
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    if(root->data<target)
        return dfs(root->right,target);
    else
        return dfs(root->left,target);
}

int main(){
    Node* root=newNode(4);
    root->left=newNode(2);
    root->right=newNode(6);
    root->left->left=newNode(1);
    root->left->right=newNode(3);
    root->right->left=newNode(5);
    root->right->right=newNode(7);
    insertNode(root,10);
    dfs(root,10);
    return 0;
}