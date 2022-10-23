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

// Time Complexity: O(N) because in worst case we will be visiting all the Nodes.
// Space Complexity: O(H) or O(N) In case of skew Tree, the auxilary stack space will be O(H) or O(N).

Node* lowestCommonAncestor(Node* root,Node* a,Node* b){
    if(root==NULL || root==a || root==b)
        return root;
    Node* left=lowestCommonAncestor(root->left,a,b);
    Node* right=lowestCommonAncestor(root->right,a,b);
    if(left==NULL)
        return right;
    else if(right==NULL)
        return left;
    else
        return root;
}

int main(){
    Node* root= newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    root->right->right=newNode(7);
    Node*ans=lowestCommonAncestor(root,root->right->right,root->right->left);
    cout<<"The Lowest Common Ancestor of Node A("<<root->right->left->data<<") and Node B("<<root->right->right->data<<"): "<<ans->data<<endl;
    return 0;
}