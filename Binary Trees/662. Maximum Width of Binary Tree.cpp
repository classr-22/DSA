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
    int widthOfBinaryTree(TreeNode* root) {

        if (!root)
            return 0;

        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int rightmost=0;
        int leftmost=0;
        int ans = 0;
        
        while(!q.empty())
        {
            int len = q.size();
            int mini = q.front().second;
            for(int i=0;i<len;i++)
            {
                auto root1 = q.front();
                q.pop();
                
                TreeNode* root2 = root1.first;
                long long pos = root1.second-mini;
                
                if(i==0)
                    leftmost=pos;
                if(i==len-1)
                    rightmost=pos;
                
                
                if(root2->left!=NULL)
                    q.push({root2->left,pos*2+1});
                if(root2->right!=NULL)
                    q.push({root2->right,pos*2+2});
            }
            ans = max(ans,(rightmost-leftmost+1));
        }
        
        return ans;
    }
};
