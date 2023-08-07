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
    void flatten(TreeNode* root) {

        if(root==NULL)
            return;

        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* root1 = st.top();
            st.pop();
            
             if(root1->right)
                st.push(root1->right);

            if(root1->left)
                st.push(root1->left);
           
            
            if(!st.empty())
            {
                root1->right=st.top();
                root1->left=NULL;
            }
        }
    }
};
