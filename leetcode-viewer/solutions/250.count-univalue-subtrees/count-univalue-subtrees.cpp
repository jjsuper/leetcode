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
    int countUnivalSubtrees(TreeNode* root) {
        if(root==NULL) return 0;
        
        int left=countUnivalSubtrees(root->left);
        int right=countUnivalSubtrees(root->right);
        
        if(isUnival(root, root->val))
            return left+right+1;
        else
            return left+right;
    }
    
private:
    bool isUnival(TreeNode *root, int val) {
        if (!root) return true;
        return root->val == val && isUnival(root->left, val) && isUnival(root->right, val);
    }
};