/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {

        if(root==NULL)
            return 0;

        queue<TreeNode*> q;
        q.push(root);
        int count = 1;
        
        while(!q.empty())
        {
            auto root1 = q.front();
            q.pop();
            
            if(root1->left!=NULL)
            {
                q.push(root1->left);
                count++;
            }
            
            if(root1->right!=NULL)
            {
                q.push(root1->right);
                count++;
            }
        }
        
        return count;
        
    }
};
