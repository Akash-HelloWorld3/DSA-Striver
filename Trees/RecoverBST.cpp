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
// Space Complexity: O(N) because of auxilary stack space.

Node* first,*middle,*last,*pre;

void inorder(Node* root){
    if(root==NULL)
        return;
    inorder(root->left);
    if(pre!=NULL && root->data < pre->data){
        if(first==NULL){
            first=pre;
            middle=root;
        }
        else
            last=root;
    }
    pre=root;
    inorder(root->right);
    return;
}

void inorderPrint(Node* root){
    if(root==NULL)
        return;
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
    return;
}
int main(){
    Node* root=newNode(7);
    root->left=newNode(2);
    root->right=newNode(6);
    root->left->left=newNode(1);
    root->left->right=newNode(3);
    root->right->left=newNode(5);
    root->right->right=newNode(4);
    cout<<"Before Swapping: ";
    inorderPrint(root);
    cout<<endl;
    inorder(root);
    if(first && last)
        swap(first->data,last->data);
    else if(first && middle)
        swap(first->data,middle->data);
    cout<<"After Swapping: ";
    inorderPrint(root);
    cout<<endl;
    return 0;
}