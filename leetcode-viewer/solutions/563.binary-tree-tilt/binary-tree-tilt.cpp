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
    int findTilt(TreeNode* root) {
        findsum(root);
        return tilt;
    }
private:
    int findsum(TreeNode* root) {
        if(root==NULL) {
            return 0;
        }
        int left=findsum(root->left);
        int right=findsum(root->right);
        tilt+=abs(left-right);
        return root->val+left+right;
    }
    int tilt=0;
};