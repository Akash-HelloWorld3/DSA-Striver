#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef struct Node{
    int data;
    Node *left;
    Node *right;
}Node;

Node* newNode(int val){
    Node* node= (Node*)malloc(sizeof(Node));
    node->data=val;
    node->left=NULL;
    node->right=NULL;
    return node;
}

void inorder(Node* root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    return;
}

class Tree{
    public:
        int data;
        Tree* left;
        Tree* right;

        Tree(int val){
            data=val;
            left=NULL;
            right=NULL;
        }
};

class TreeList{
    public:
        int data;
        vector<TreeList*>children;
    TreeList(int val){
        data=val;
    }
};

TreeList* inputOfTreeList(){
    int value;
    cout<<"Enter the root data for the TreeList: ";
    cin>>value;
    TreeList* root= new TreeList(value);
    queue<TreeList*>q;
    q.push(root);
    while(!q.empty())
    {
        TreeList* front=q.front();
        q.pop();
        int N;
        cout<<"Enter the Number of child of the Node "<<front->data<<" :";
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int val;
            cout<<"Enter the data for "<<i<<" th child of the Node "<<front->data<<" :";
            cin>>val;
            TreeList* child= new TreeList(val);
            front->children.push_back(child);
            q.push(child);
        }
    }
    return root;
}

void inorderNary(TreeList* root){
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++){
        inorderNary(root->children[i]);
    }
}


int main(){
    cout<<"Hello World!"<<endl;
    Node* root= newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    root->right->right=newNode(7);
    cout<<"Using structure: ";
    inorder(root);
    cout<<endl;
    Tree* root1 = new Tree(1);
    root1->left = new Tree(2);
    root1->right = new Tree(3);
    root1->left->left = new Tree(4);
    root1->left->right = new Tree(5);
    root1->right->left = new Tree(6);
    root1->right->right = new Tree(7);
    cout<<"Using Class: ";
    inorder(root);
    cout<<endl;
    TreeList* root2= inputOfTreeList();
    cout<<"Using Class for N-ary Tree: ";  
    inorderNary(root2);
    cout<<endl;
    return 0;
 }