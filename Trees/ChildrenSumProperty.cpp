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

// Time Complexity: O(N) because we are visiting all the Nodes.
// Space Complexity: O(H) or O(N) because in skew tree the auxilary stack space will be O(N).

void changeTree(Node* root) {
    if(root==NULL || (root->left==NULL && root->right==NULL))
        return;
    if(root->left!=NULL && root->right!=NULL){
        if(root->data<=root->left->data+root->right->data)
            root->data=root->left->data+root->right->data;
        else{
            root->left->data=root->data;
            root->right->data=root->data;
        }
     }
    else if(root->left!=NULL){
        if(root->data<=root->left->data)
            root->data=root->left->data;
        else
            root->left->data=root->data;
    }
    else if(root->right!=NULL){
        if(root->data<=root->right->data)
            root->data=root->right->data;
        else
            root->right->data=root->data;
    }
    changeTree(root->left);
    changeTree(root->right);
    if(root->left!=NULL && root->right!=NULL){
        if(root->data==root->left->data+root->right->data)
            return;
        else if(root->data<root->left->data+root->right->data)
            root->data=root->left->data+root->right->data;
     }
    else if(root->left!=NULL){
        if(root->data==root->left->data)
            return;
        else
            root->data=root->left->data;
        return;
    }
    else if(root->right!=NULL){
        if(root->data==root->right->data)
            return;
        else
            root->data=root->right->data;
        return;
    }
    return;
}

void changeTree1(Node* root){
    if(root==NULL)
        return;
    int child=0;
    if(root->left)
        child+=root->left->data;
    if(root->right)
        child+=root->right->data;
    if(child>=root->data)
        root->data=child;
    else{
        if(root->left)
            root->left->data=root->data;
        if(root->right)
            root->right->data=root->data;
    }
    changeTree1(root->left);
    changeTree1(root->right);
    int tot=0;
    if(root->left)
        tot+=root->left->data;
    if(root->right)
        tot+=root->right->data;
    if(root->left!=NULL || root->right!=NULL)
        root->data=tot;
    return;
}

void dfs(Node* root){
    if(root==NULL)
        return;
    dfs(root->left);
    cout<<root->data<<" ";
    dfs(root->right);
}
int main(){
    Node* root= newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    root->right->right=newNode(7);
    // changeTree(root);
    changeTree1(root);
    dfs(root);
    return 0;
}