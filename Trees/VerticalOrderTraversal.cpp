#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
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

// Time Complexity: O(N)+O(LogN) because we are visiting all the nodes and we are storing the datas in multiset in sorted order.
// Space Complexity: O(N) because we are storing all the nodes values.

vector<vector<int> > verticalOrderTraversal(Node* root){
    vector<vector<int> >ans;
    if(root==NULL)
        return ans;
        queue<pair<Node*,pair<int,int> > >q;
        map<int,map<int,multiset<int> > >hash;
        q.push({root,{0,0}});
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto it=q.front();
                q.pop();
                hash[it.second.first][it.second.second].insert(it.first->data);
                if(it.first->left!=NULL)
                    q.push({it.first->left,{it.second.first-1,it.second.second+1}});
                if(it.first->right!=NULL)
                    q.push({it.first->right,{it.second.first+1,it.second.second+1}});
            }
        }
        for(auto it:hash){
            vector<int>carry;
            for(auto it1:it.second){
                carry.insert(carry.end(),it1.second.begin(),it1.second.end());
            }
            ans.push_back(carry);
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
    vector<vector<int> >ans=verticalOrderTraversal(root);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}