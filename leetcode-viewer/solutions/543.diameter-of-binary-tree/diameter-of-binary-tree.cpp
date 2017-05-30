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
    int diameterOfBinaryTree(TreeNode* root) {
        maxdepth(root);
        return diameter;
    }
private:
    int diameter=0;
    int maxdepth(TreeNode* root) {
        if(root==NULL) return 0;
        int left=maxdepth(root->left);
        int right=maxdepth(root->right);
        diameter=max(diameter, left+right);
        return max(left, right)+1;
    }
};