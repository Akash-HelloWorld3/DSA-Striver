#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
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

void findParent(Node* root,unordered_map<Node*,Node*>&map){
    if(root==NULL)
        return;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            Node* temp=q.front();
            q.pop();
            if(temp->left!=NULL){
                map[temp->left]=temp;
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                map[temp->right]=temp;
                q.push(temp->right);
            }
        }
    }
    return;
}
vector<int> distanceK(Node* root, Node* target, int k) {
    vector<int>ans;
    if(root==NULL)
        return ans;
    unordered_map<Node*,Node*>map;
    findParent(root,map);
    unordered_map<Node*,bool>visit;
    queue<Node*>q;
    q.push(target);
    visit[target]=true;
    int curr_level=0;
    while(!q.empty()){
        int size=q.size();
        if(curr_level++==k)
            break;
        for(int i=0;i<size;i++){
            Node* temp=q.front();
            q.pop();
            if(temp->left!=NULL && !visit[temp->left]){
                visit[temp->left]=1;
                q.push(temp->left);
            }
            if(temp->right!=NULL && !visit[temp->right]){
                visit[temp->right]=true;
                q.push(temp->right);
            }
            if(map[temp] && !visit[map[temp]]){
                visit[map[temp]]=true;
                q.push(map[temp]);
            }
        }
    }
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        ans.push_back(temp->data);       
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
    vector<int>ans=distanceK(root,root->right->right,2);
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}