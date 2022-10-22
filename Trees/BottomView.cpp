#include<iostream>
#include<vector>
#include<queue>
#include<map>
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

vector <int> bottomView(Node *root) {
    vector<int>ans;
    if(root==NULL)
        return ans;
    queue<pair<Node*,int>>q;
    map<int,int>mp;
    q.push({root,0});
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            auto it=q.front();
            q.pop();
            mp[it.second]=it.first->data;
            if(it.first->left!=NULL)
                q.push({it.first->left,it.second-1});
            if(it.first->right!=NULL)
                q.push({it.first->right,it.second+1});
        }
    }
    for(auto it:mp)
        ans.push_back(it.second);
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
    vector<int> ans=bottomView(root);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}