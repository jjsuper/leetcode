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
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        stack<TreeNode*> nodeStack;
        
        nodeStack.push(root);
        TreeNode* pre=new TreeNode(0);
   
        while(!nodeStack.empty())
        {
            TreeNode* node=nodeStack.top();
            nodeStack.pop();
            
            if(node->right!=NULL) nodeStack.push(node->right);
            if(node->left!=NULL) nodeStack.push(node->left);
            
            node->left=node->right=NULL;
            pre->right=node;
            pre=pre->right;
        }
    }
};