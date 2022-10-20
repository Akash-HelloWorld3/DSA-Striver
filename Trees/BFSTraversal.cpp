#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef struct Node{
    int data;
    Node *left;
    Node *right;
}Node;

Node* newNode(int val){
    Node* node= (Node*)malloc(sizeof(Node));
    node->data=val;
    node->left=NULL;
    node->right=NULL;
    return node;
}

void levelOrderTraversal(Node* root){
    if(root==NULL)
        return;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                Node* temp=q.front();
                q.pop();
                cout<<temp->data<<" ";
                if(temp->left!=NULL)
                    q.push(temp->left);
                if(temp->right!=NULL)
                    q.push(temp->right);
            }
            cout<<endl;
        }
    return;
}

int main(){
    Node* root= newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    root->right->right=newNode(7);
    cout<<"Level Order Traversal: "<<endl;
    levelOrderTraversal(root);
    return 0;
}