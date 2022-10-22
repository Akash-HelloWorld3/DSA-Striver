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

// Time Complexity: O(N) because we are visiting N nodes.
// Space Complexity: O(N) if all the node are present in the last level, then the queue would approximately contain O(N) Space.

void zigZagTraversal(Node* root,vector<vector<int> >&ans){
    if(root==NULL)
        return;
    queue<Node*>q;
    bool flag=true;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        vector<int>carry(size);
        for(int i=0;i<size;i++){
            Node* temp=q.front();
            q.pop();
            int index=flag?i:(size-i-1);
            carry[index]=temp->data;
            if(temp->left!=NULL)
                q.push(temp->left);
            if(temp->right!=NULL)
                q.push(temp->right);
        }
        ans.push_back(carry);
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
    vector<vector<int> >ans;
    zigZagTraversal(root,ans);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}