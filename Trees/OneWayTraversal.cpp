#include<iostream>
#include<stack>
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

// Time Complexity: O(3*N)
// Space Complexity: O(3N)

void oneWayTraversal(Node* root){
    if(root==NULL)
        return;
    stack<pair<Node*,int> >st;
    st.push({root,1});
    vector<int>preorder,inorder,postorder;
    while(!st.empty()){
        auto it=st.top();
        st.pop();
        if(it.second==1){
            preorder.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->left!=NULL)
                st.push({it.first->left,1});
        }
        else if(it.second==2){
            inorder.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->right!=NULL)
                st.push({it.first->right,1});
        }
        else{
            postorder.push_back(it.first->data);
        }
    }
    cout<<"Preorder Traversal: ";
    for(auto it:preorder)
        cout<<it<<" ";
    cout<<endl<<"Inorder Traversal: ";
    for(auto it:inorder)
        cout<<it<<" ";
    cout<<endl<<"Postorder Traversal: ";
    for(auto it:postorder)
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
    cout<<"Using one way traversal: "<<endl;
    oneWayTraversal(root);
    cout<<endl;
    return 0;
}