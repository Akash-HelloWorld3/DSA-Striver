#include<iostream>
#include<math.h>
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

// Time Complexity: O (LogN)^2 because we are not visiting all the nodes which takes logn + finding the height at each level.
// Space Complexity: O(LogN) becuase of auxilary stack space.

int countNodes(Node* root){
    if(root==NULL)
        return 0;
    Node* l=root,*r=root;
    int hl=0,hr=0;
    while(l){
        hl++;
        l=l->left;
    }
    while(r){
        hr++;
        r=r->right;
    }
    if(hl==hr)
        return pow(2,hl)-1;
    return 1+countNodes(root->left)+countNodes(root->right);
}
int main(){
    Node* root= newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    root->right->right=newNode(7);
    cout<<"The No of Nodes in the Complete Binary Tree: "<<countNodes(root);
    return 0;
}