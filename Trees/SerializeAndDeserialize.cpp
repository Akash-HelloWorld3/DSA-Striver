#include<iostream>
#include<vector>
#include<queue>
#include<string>
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

// Time Complexity: O(N).
// Space Complexity: O(N).

string serialize(Node* root){
    if(root==NULL)
        return "";
    queue<Node*>q;
    q.push(root);
    string str="";
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(temp==NULL)
            str+="#,";
        else{
            str+=to_string(temp->data)+",";
        }
        if(temp!=NULL){
            q.push(temp->left);
            q.push(temp->right);
        }
    }
    return str;
}
Node* deserialize(string data){
    if(data.length()==0)
        return NULL;
    stringstream s(data);
    string str;
    getline(s,str,',');
    Node* root=newNode(stoi(str));
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        getline(s,str,',');
        if(str=="#")
            temp->left=NULL;
        else{
            Node* l=newNode(stoi(str));
            temp->left=l;
            q.push(l);
        }
        getline(s,str,',');
        if(str=="#")
            temp->right=NULL;
        else{
            Node* r=newNode(stoi(str));
            temp->right=r;
            q.push(r);
        }
    }
    return root;
}

void dfs(Node* root){
    if(root==NULL)
        return;
    dfs(root->left);
    cout<<root->data<<" ";
    dfs(root->right);
    return;
}
int main(){
    Node* root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    root->right->right=newNode(7);
    string data=serialize(root);
    Node* temp=deserialize(data);
    dfs(root);
    return 0;
}