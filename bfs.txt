#include<iostream>
#include<queue>
#include<omp.h>
using namespace std;

class TreeNode{

public:
    int data;
    TreeNode *left;
    TreeNode *right; 
    TreeNode(){
        this->left=NULL;
        this->right=NULL;
    }
    TreeNode(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
TreeNode* insert(TreeNode *root,int data){
    if(root==NULL){
        root=new TreeNode(data);
        return root;
    }
    queue<TreeNode*>q;
    q.push(root);
    while(q.empty()==false){
        TreeNode *curr=q.front();
        q.pop();
        if(curr->left==NULL){
            curr->left=new TreeNode(data);
            return root;
        }
        if(curr->right==NULL){
            curr->right=new TreeNode(data);
            return root;
        }
        q.push(curr->left);
        q.push(curr->right);
    }
    return root;
}
void bfs(TreeNode *root){
    queue<TreeNode*>q;
    q.push(root);
    while(q.empty()==false){
        int sz=q.size();
        #pragma omp parallel for
        for(int i=0;i<sz;i++){
            TreeNode* curr;
            #pragma omp critical
            {
                curr=q.front();
                q.pop();
                cout<<omp_get_thread_num()<<" "<<curr->data<<endl;
            }
            #pragma omp critical
            {
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
        }
    }
}
int main(){
    int n;
    cin>>n;
    TreeNode *root=NULL;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        root=insert(root,data);
    }
    bfs(root);
    return 0;
}