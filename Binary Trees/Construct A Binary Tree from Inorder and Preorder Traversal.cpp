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
    
    TreeNode* solve(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int,int>& mp)
    {
        if (preStart > preEnd || inStart > inEnd) return NULL;
        
        int tofind = preorder[preStart];
        TreeNode* root =new TreeNode(tofind);
        
        int pos = mp[root->val];
        int val = pos - inStart;
        
        root->left = solve(preorder,preStart+1,preStart+val,inorder,inStart,pos-1,mp);
        root->right = solve(preorder,preStart+val+1,preEnd,inorder,pos+1,inEnd,mp);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preStart = 0, preEnd = preorder.size() - 1;
        int inStart = 0, inEnd = inorder.size() - 1;
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        
        return solve(preorder, preStart, preEnd, inorder, inStart, inEnd,mp);
    }
};
