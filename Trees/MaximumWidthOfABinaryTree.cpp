#include<iostream>
#include<queue>
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

// Time Complexity: O(N) because we are visiting all the nodes.
// Space Complexity: O(N) because we are using queue data structure.

int maximumWidthOfABinaryTree(Node* root){
    if(root==NULL)
        return 0;
    int ans=0;
    queue<pair<Node*,int> >q;
    q.push({root,0});
    while(!q.empty()){
        int size=q.size();
        int start=q.front().second;
        int end=q.back().second;
        ans=max(ans,end-start+1);
        for(int i=0;i<size;i++){
            auto it=q.front();
            q.pop();
            int index=it.second;
            if(it.first->left!=NULL)
                q.push({it.first->left,(long)index*2+1});
            if(it.first->right!=NULL)
                q.push({it.first->right,(long)index*2+2});
        }
    }
    return ans;
}

int main(){
    Node* root= newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    root->right->right=newNode(7);
    cout<<"The Maximum Width of a Binary Tree: "<<maximumWidthOfABinaryTree(root);
    return 0;
}