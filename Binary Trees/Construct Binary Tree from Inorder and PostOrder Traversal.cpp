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
    
    TreeNode* solve(vector<int>& postorder, int postStart, int postEnd, vector<int>& inorder, int inStart, int inEnd, map<int,int>& mp)
    {
        if(postStart>postEnd || inStart>inEnd) return NULL;

        int tofind = postorder[postEnd];
        TreeNode* root = new TreeNode(tofind);
        int pos = mp[tofind];
        int val = inEnd-pos;
        
        
        root->left = solve(postorder,postStart,postEnd-val-1,inorder,inStart,pos-1,mp);
        root->right = solve(postorder,postEnd-val,postEnd-1,inorder,pos+1,inEnd,mp);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postStart = 0 ,postEnd = postorder.size()-1;
        int inStart = 0,inEnd = inorder.size()-1;
        
        map<int,int> mp;
        
        for(int i=0;i<=inEnd;i++)
        {
            mp[inorder[i]]=i;
        }
        
        return solve(postorder,postStart,postEnd,inorder,inStart,inEnd,mp);
    }
};
