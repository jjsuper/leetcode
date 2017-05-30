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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ret;
        if(root==NULL) return 0;
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
        
        return ret[k-1];
        
        
        
        
        
        
    }
};