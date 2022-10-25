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

int findFloor(Node* root,int key){
    int floor=-1;
    while(root){
        if(root->data==key){
            floor=root->data;
            return floor;
        }
        if(key<root->data)
            root=root->left;   
        else{
            floor=root->data;
            root=root->right;
        }       
    }
    return floor;
}

int main(){
    Node* root=newNode(4);
    root->left=newNode(2);
    root->right=newNode(6);
    root->left->left=newNode(1);
    root->left->right=newNode(3);
    root->right->left=newNode(5);
    root->right->right=newNode(8);
    int ans=findFloor(root,7);
    if(ans!=-1)
        cout<<"Found the Floor: "<<ans<<endl;
    else
        cout<<"The Floor does not exit"<<endl;
    return 0;
}