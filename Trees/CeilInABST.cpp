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
// Space Complexity: O(1) we are not using extra space.

int findCeil(Node* root,int key){
    int ceil=-1;
    while(root){
        if(root->data==key){
            ceil=root->data;
            return ceil;
        }
        if(key<root->data){
            ceil=root->data;
            root=root->left;
        }    
        else
            root=root->right;
    }
    return ceil;
}

int main(){
    Node* root=newNode(4);
    root->left=newNode(2);
    root->right=newNode(6);
    root->left->left=newNode(1);
    root->left->right=newNode(3);
    root->right->left=newNode(5);
    root->right->right=newNode(8);
    int ans=findCeil(root,7);
    if(ans!=-1)
        cout<<"Found the Ceil: "<<ans<<endl;
    else
        cout<<"The Ceil does not exit"<<endl;
    return 0;
}