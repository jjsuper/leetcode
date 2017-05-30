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
    int longestConsecutive(TreeNode* root) {
        if(!root) return 0;
        return count(root, root->val-1, 0);
    }
private:
    int count(TreeNode* root, int prev, int len) {
        if(!root) return len;
        len=(root->val == prev+1)?len+1:1;
        return max(len, max(count(root->left, root->val, len), count(root->right, root->val, len)));
    }
};