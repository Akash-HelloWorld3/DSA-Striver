#include<iostream>
#include<vector>
#include <stack>
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

// Time Complexity: O(N) because we are visting every node.
// Space Complexity: O(N) or O(H) where H is the height of the Binary Tree. In case we are having right node only 
//                                on the left side of the binary tree.
// Ex:
//          ------- 1 --------
//      --- 2 ---            3
//   -- 4 --    5
// - 6 -   7
// 8   9  
//
void preorderTraversal(Node* root)
{
    if(root==NULL)
        return;
    stack<Node*>st;
    Node* temp=root;
    st.push(temp);
    while(!st.empty())
    {
        Node* curr=st.top();
        st.pop();
        cout<<curr->data<<" ";      
        if(curr->right!=NULL)
            st.push(curr->right);
        if(curr->left!=NULL)
            st.push(curr->left);
    }
    return;
}

// Time Complexity: O(N) because we are visting every node.
// Space Complexity: O(N) or O(H) where H is the height of the Binary Tree. In case of skew tree we are pushing the node till
//                                it becomes NULL.
// Ex:
//          ------- 1
//      --- 2 
//   -- 4 
// - 6
// 8 
//

void inorderTraversal(Node* root){
    if(root==NULL)
        return;
    stack<Node*>st;
    Node* temp=root;
    while(true){
        if(temp!=NULL){
            st.push(temp);
            temp=temp->left;
        }
        else{
            if(st.empty())
                break;
            temp=st.top();
            st.pop();
            cout<<temp->data<<" "; 
            temp=temp->right;
        }
    }
    return;
}

// Time Complexity: O(N) because we are visting every node.
// Space Complexity: O(2N) becasuse we are using 2 stacks.
// Using 2 Stacks

void postorderTraversal1(Node* root)
{
    if(root==NULL)
        return;
    stack<Node*>st1,st2;
    Node* temp=root;
    st1.push(temp);
    while(!st1.empty())
    {
        Node* curr=st1.top();
        st1.pop();
        st2.push(curr);
        if(curr->left!=NULL)
            st1.push(curr->left);
        if(curr->right!=NULL)
            st1.push(curr->right);
    }
    while(!st2.empty())
    {
        cout<<st2.top()->data<<" ";
        st2.pop();
    }
    return;
}

// Time Complexcity: O(2N)
// Space Complexity: O(N)
// Using 1 Stack

void postorderTraversal2(Node* root){
    vector<int>ans;
    stack<Node*>st;
    Node* curr=root;
    while(curr!=NULL || !st.empty()){
        if(curr!=NULL){
            st.push(curr);
            curr=curr->left;
        }
        else{
            Node* temp=st.top()->right;
            if(temp==NULL){
                temp=st.top();
                st.pop();
                ans.push_back(temp->data);
                while(!st.empty() && temp==st.top()->right){
                    temp=st.top();
                    st.pop();
                    ans.push_back(temp->data);
                }
            }
            else
                curr=temp;
        }

    }
    for(auto it:ans)
        cout<<it<<" ";
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
    cout<<"Preorder Traversal: ";
    preorderTraversal(root);
    cout<<endl;
    cout<<"Inorder Traversal: ";
    inorderTraversal(root);
    cout<<endl;
    cout<<"Postorder Traversal using 2 stacks: ";
    postorderTraversal1(root);
    cout<<endl;
    cout<<"Postorder Traversal using 1 stacks: ";
    postorderTraversal2(root);
    cout<<endl;
    return 0;
}