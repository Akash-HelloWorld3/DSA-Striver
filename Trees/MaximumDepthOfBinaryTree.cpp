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

// Time Complexity: O(N) because we are visiting N nodes.
// Space Complexity: O(N) because in case of skew tree the auxilary stack space will be O(N) where N is the no of nodes.

void MaxDepth1(Node* root,int count,int &maxi){
    if(root==NULL){
        maxi=max(count,maxi);
        return;
    }
    MaxDepth1(root->left,count+1,maxi);
    MaxDepth1(root->right,count+1,maxi);
}

// Time Complexity: O(N) because we are visiting N nodes.
// Space Complexity: O(N) because in case of skew tree the auxilary stack space will be O(N) where N is the no of nodes.

int MaxDepth2(Node* root){
    if(root==NULL)
        return 0;
    int left=1+MaxDepth2(root->left);
    int right=1+MaxDepth2(root->right);
    return max(left,right);
}

// Time Complexity: O(N) because we are visiting N nodes.
// Space Complexity: O(N) because in case of skew tree the auxilary stack space will be O(N) where N is the no of nodes.

int MaxDepth3(Node* root){
    if(root==NULL)
        return 0;
    return 1+max(MaxDepth3(root->left),MaxDepth3(root->right));
}

// Time Complexity: O(N) because we are visiting N nodes.
// Space Complexity: O(N) because we are storing in Queue, in worst case if all the nodes are present in the last level.

int MaxDepth4(Node* root){
    if(root==NULL)
        return 0;
    queue<Node*>q;
    q.push(root);
    int count=0;
    while(!q.empty()){
        count++;
        int size=q.size();
        for(int i=0;i<size;i++){
            Node* temp=q.front();
            q.pop();
            if(temp->left!=NULL)
                q.push(temp->left);
            if(temp->right!=NULL)
                q.push(temp->right);
        }
    }
    return count;
}
 
int main(){
    Node* root= newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    root->right->right=newNode(7);
    int maxi=0;
    MaxDepth1(root,0,maxi);
    cout<<maxi<<endl;
    cout<<MaxDepth2(root)<<endl;
    cout<<MaxDepth3(root)<<endl;
    cout<<MaxDepth4(root)<<endl;
    return 0;
}