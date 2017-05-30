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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(root==NULL) return ret;
        
        stack<TreeNode*> mystack;
        mystack.push(root);
        
        while(!mystack.empty())
        {
            
            TreeNode* node;
            node=mystack.top();
            ret.push_back(node->val);
            mystack.pop();
         
            
            if(node->right!=NULL) mystack.push(node->right);
            if(node->left!=NULL) mystack.push(node->left);
            
            
        }
        
        
        
        return ret;
    }
};