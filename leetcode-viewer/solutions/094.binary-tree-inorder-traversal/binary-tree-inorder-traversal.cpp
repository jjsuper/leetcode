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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(root==NULL) return ret;
        stack<TreeNode*> st;
        TreeNode* node=root;
        
        while(node!=NULL)
        {
            st.push(node);
            node=node->left;
        }
        
        while(!st.empty())
        {
            node=st.top();
            st.pop();
            ret.push_back(node->val);
            
            node=node->right;
            while(node!=NULL)
            {
                st.push(node);
                node=node->left;
            }
        }
        
        return ret;
    }
};