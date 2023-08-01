/************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<map>
int dfs(BinaryTreeNode<int>* start,map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> mp)
{
    queue<BinaryTreeNode<int>*> q;
    map<BinaryTreeNode<int>*,bool> visited;
    int count=0;
    q.push(start);
    visited[start]=1;
    
    while(!q.empty())
    {
        int len = q.size();
        for(int i=0;i<len;i++)
        {
            auto root = q.front();
            q.pop();
            
            if(root->left!=NULL && visited[root->left]!=1)
            {
                q.push(root->left);
                visited[root->left]=1;
            }
            if(root->right!=NULL && visited[root->right]!=1)
            {
                q.push(root->right);
                visited[root->right]=1;
            }
            if(mp[root] && visited[mp[root]]!=1)
            {
                q.push(mp[root]);
                visited[mp[root]]=1;
            }
        }
        count++;
    }
    
    return count-1;
}

int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    // Write your code here
    queue<BinaryTreeNode<int>*> q;
    map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> mp;
    BinaryTreeNode<int>* s = root;
    q.push(root);
    
    while(!q.empty())
    {
        auto root1 = q.front();
        q.pop();   
        
        if(root1->data==start)
            s=root1;
        
        if(root1->left!=NULL)
        {
            q.push(root1->left);
            mp[root1->left]=root1;
        }
            
        if(root1->right!=NULL)
        {
            q.push(root1->right); 
            mp[root1->right]=root1;
        }
    }
    
    return dfs(s,mp);
}
