#include<iostream>
#include<vector>
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
// Space Complexity: O(H) or O(N) In case of skew Tree, the auxilary stack space will be O(H) or O(N).

bool rootToNode(Node* root,int target,vector<int>&ans){
    if(root==NULL)
        return false;
    if(root->data==target){
        ans.push_back(root->data);
        return true;
    }
    ans.push_back(root->data);
    if(rootToNode(root->left,target,ans) || rootToNode(root->right,target,ans))
        return true;
    ans.pop_back();
    return false;
}

int main(){
    Node* root= newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    root->right->right=newNode(7);
    vector<int>ans;
    if(rootToNode(root,10,ans)){
        cout<<"The Path: ";
        for(auto it:ans){
            cout<<it<<" ";
        }
    }
    else
        cout<<"There is no path";
    return 0;
}