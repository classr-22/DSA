/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    vector<int> dfs(TreeNode* target, int k,vector<int>& vec, unordered_map<TreeNode*,TreeNode*> mp)
    {
        queue<TreeNode*> q;
        int visited[501]={0};
        q.push(target);
        visited[target->val]=1;
        int dis=0;
        
        while(!q.empty())
        {
            int len = q.size();
            for(int i=0;i<len;i++)
            {
                auto root1 = q.front();
                q.pop(); 
                
                if(root1->left!=NULL && visited[root1->left->val]!=1)
                {
                    q.push(root1->left);
                    visited[root1->left->val]=1;
                }
                if(root1->right!=NULL && visited[root1->right->val]!=1)
                {
                    q.push(root1->right);
                    visited[root1->right->val]=1;
                }
                if(mp.find(root1)!=mp.end() && visited[mp[root1]->val]!=1)
                {
                    q.push(mp[root1]);
                    visited[mp[root1]->val]=1;   
                }
            }
            dis++;
            if(dis==k)
            {
                while(!q.empty())
                {
                    vec.push_back(q.front()->val);
                    q.pop();
                }
                return vec;
            }
        }
        return vec;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> vec;

        if(k==0)
        {
            vec.push_back(target->val);
            return vec;
        }

        queue<TreeNode*> q;
        unordered_map<TreeNode*,TreeNode*> mp;
        q.push(root);
        
        while(!q.empty())
        {
            auto root1 = q.front();
            q.pop();
            
            if(root1->left!=NULL)
            {
                mp[root1->left]=root1;
                q.push(root1->left);
            }
            
            if(root1->right!=NULL)
            {
                mp[root1->right]=root1;
                q.push(root1->right);
            }
        }
        
        return dfs(target,k,vec,mp);
    }
};
