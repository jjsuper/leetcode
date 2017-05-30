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
private:
    int maxValue=INT_MIN;
    int maxPathDown(TreeNode* root) {
        if(root==NULL) return 0;
        int left=max(0, maxPathDown(root->left));
        int right=max(0, maxPathDown(root->right));
        maxValue=max(maxValue, left+right+root->val);
        return max(left, right)+root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        maxPathDown(root);
        return maxValue;
    }
};