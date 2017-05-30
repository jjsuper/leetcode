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
    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root, false);
    }
private:
    int dfs(TreeNode* root, bool isLeftLeaf) {
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL && isLeftLeaf) return root->val;
        return dfs(root->left, true)+dfs(root->right, false);
    }
};


