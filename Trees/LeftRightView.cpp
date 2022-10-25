#include<iostream>
#include<vector>
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

// Time Complexity: O(N)
// Space Complexity: O(N)

void leftView(Node* root,int level,vector<int>&ans){
    if(root==NULL)
        return;
    if(level==ans.size())
        ans.push_back(root->data);
    leftView(root->left,level+1,ans);
    leftView(root->right,level+1,ans);
}

// Time Complexity: O(N)
// Space Complexity: O(N)

void rightView(Node* root,int level,vector<int>&ans){
    if(root==NULL)
        return;
    if(level==ans.size())
        ans.push_back(root->data);
    rightView(root->right,level+1,ans);
    rightView(root->left,level+1,ans);
}

// Time Complexity: O(N)
// Space Complexity: O(N)

void leftRightViewBFS(Node* root,vector<int>&left,vector<int>&right){
    if(root==NULL)
        return;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            Node* temp=q.front();
            q.pop();
            if(i==0)
                left.push_back(temp->data);
            if(i==size-1)
                right.push_back(temp->data);
            if(temp->left!=NULL)
                q.push(temp->left);
            if(temp->right!=NULL)
                q.push(temp->right);
        }
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
    vector<int> left,right,left1,right1;
    leftView(root,0,left);
    rightView(root,0,right);
    leftRightViewBFS(root,left1,right1);
    cout<<"Left View of the Binary Tree: ";
    for(int i=0;i<left.size();i++)
        cout<<left[i]<<" ";
    cout<<endl<<"Right View of the Binary Tree: ";
    for(int i=0;i<right.size();i++)
        cout<<right[i]<<" ";
    cout<<endl<<"Using BFS Left View of the Binary Tree: ";
    for(int i=0;i<left1.size();i++)
        cout<<left1[i]<<" ";
    cout<<endl<<"Using BFS Right View of the Binary Tree: ";
    for(int i=0;i<right1.size();i++)
        cout<<right1[i]<<" ";
    return 0;
}