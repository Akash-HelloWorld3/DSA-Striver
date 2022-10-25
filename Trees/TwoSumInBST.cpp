#include<iostream>
#include<vector>
#include<stack>
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

void inorder(Node* root,vector<int>&ans){
    if(root==NULL)
        return;
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
    return;
}

bool findPair1(vector<int>&ans,int k){
    int s=0,e=ans.size()-1;
    while(s<e){
        int sum=ans[s]+ans[e];
        if(sum==k)    
            return true;
        if(sum<k)
            s++;
        else
            e--;
    }
    return false;
}

// Time Complexity: O(N).
// Space Complexity: O(H)*2 which is less the O(N). because we are using Two Stack.

void pushAll(Node* root, bool isReverse,stack<Node*>&st1,stack<Node*>&st2){
    while(root){
        if(isReverse){
            st2.push(root);
            root=root->right;
        }
        else{
            st1.push(root);
            root=root->left;
        }
    }
}

void start(Node* root,bool isReverse,stack<Node*>&st1,stack<Node*>&st2){
    if(isReverse)
        pushAll(root,isReverse,st1,st2);
    else
        pushAll(root,isReverse,st1,st2);
}

int next(bool isReverse,stack<Node*>&st1,stack<Node*>&st2){
    if(isReverse){
        Node* temp=st2.top();
        st2.pop();
        pushAll(temp->left,isReverse,st1,st2);
        return temp->data;
    }
    else{
        Node* temp=st1.top();
        st1.pop();
        pushAll(temp->right,isReverse,st1,st2);
        return temp->data;
    }
}

bool findPair2(Node* root,int k,stack<Node*>&st1,stack<Node*>&st2){
        start(root,true,st1,st2);
        start(root,false,st1,st2);
        int l=next(false,st1,st2);
        int r=next(true,st1,st2);
        while(l<r){
            int sum=l+r;
            if(sum==k)
                return true;
            if(sum<k)
                l=next(false,st1,st2);
            else
                r=next(true,st1,st2);
        }
        return false;
}

int main(){
    Node* root=newNode(4);
    root->left=newNode(2);
    root->right=newNode(6);
    root->left->left=newNode(1);
    root->left->right=newNode(3);
    root->right->left=newNode(5);
    root->right->right=newNode(7);
    int k=9;
 //   <------------------ Method 1 ---------------------->

    vector<int>ans;
    inorder(root,ans);
    bool x=findPair1(ans,k);
    if(x)
        cout<<"Pair Found"<<endl;
    else 
        cout<<"Pair Not Found"<<endl;

 //   <------------------ Method 2 ---------------------->
    stack<Node*>st1,st2;
    bool y=findPair2(root,k,st1,st2);
    if(y)
        cout<<"Pair Found"<<endl;
    else 
        cout<<"Pair Not Found"<<endl;
    return 0;
}