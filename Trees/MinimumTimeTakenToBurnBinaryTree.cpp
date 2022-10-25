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

void findParent(Node* root,unordered_map<Node*,Node*>&map,unordered_map<Node*,bool>&visit, int start,queue<Node*>&find){
    if(root==NULL)
        return;
    queue<Node*>pq;
    pq.push(root);
    while(!pq.empty()){
        int size=pq.size();
        for(int i=0;i<size;i++){
            Node* temp=pq.front();
            pq.pop();
            if(temp->data==start){
                visit[temp]=true;
                find.push(temp);
            }
            if(temp->left!=NULL){
                map[temp->left]=temp;
                pq.push(temp->left);
            }
            if(temp->right!=NULL){
                map[temp->right]=temp;
                pq.push(temp->right);
            }
        }
    }
    return;
}

int amountOfTime(Node* root, int start) {
    if(root==NULL)
        return 0;
    unordered_map<Node*,Node*>map;
    unordered_map<Node*,bool>visit;
    queue<Node*>q;
    findParent(root,map,visit,start,q);
    vector<int>ans;
    int curr_level=0;
    while(!q.empty()){
        int size=q.size();
        int flag=0;
        for(int i=0;i<size;i++){
            Node* temp=q.front();
            q.pop();
            if(temp->left!=NULL && !visit[temp->left]){
                visit[temp->left]=1;
                q.push(temp->left);
                flag=1;
            }
            if(temp->right!=NULL && !visit[temp->right]){
                visit[temp->right]=true;
                q.push(temp->right);
                flag=1;
            }
            if(map[temp] && !visit[map[temp]]){
                visit[map[temp]]=true;
                q.push(map[temp]);
                flag=1;
            }
        }
        if(flag)
            curr_level++;
    }
    return curr_level;     
}

int main(){
    Node* root= newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    root->right->right=newNode(7);
    cout<<"The Minimum Time Taken to burn the Binary Tree: "<<amountOfTime(root,2);
    return 0;
}