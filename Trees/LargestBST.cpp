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

typedef struct NodeValue {
    int maxNode, minNode, sum;
    NodeValue(int minNode, int maxNode, int sum) {
        maxNode = maxNode;
        minNode = minNode;
        sum = sum;
    }
}NodeValue;

NodeValue findLarge(Node* root,int &sum){
    if(root==NULL)
        return NodeValue(INT_MAX,INT_MIN,0);
    auto left=findLarge(root->left,sum);
    auto right=findLarge(root->right,sum);
    if(left.maxNode < root->data && root->data < right.minNode){
        sum=max(sum,left.sum + right.sum + root->data);
        return NodeValue(min(root->data,left.minNode),max(root->data,right.maxNode),left.sum + right.sum + root->data);
        }
    return NodeValue(INT_MIN, INT_MAX, INT_MIN);
}

int main(){
    Node* root=newNode(4);
    root->left=newNode(2);
    root->right=newNode(6);
    root->left->left=newNode(1);
    root->left->right=newNode(3);
    root->right->left=newNode(5);
    root->right->right=newNode(7);
    int sum=0;
    findLarge(root,sum);
    cout<<"The Largest BST Sum: "<<sum<<"."<<endl;
    return 0;
}