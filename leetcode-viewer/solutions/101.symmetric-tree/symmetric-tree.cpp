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
    bool isSymmetric(TreeNode* root) {
        return !root || isEqual(root->left, root->right);
    }
private:
    bool isEqual(TreeNode* left, TreeNode* right) {
        if(left && right) 
            return left->val==right->val && isEqual(left->left, right->right) && isEqual(left->right, right->left);
        return !left && !right;
    }
};