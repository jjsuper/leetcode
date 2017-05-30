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
    int findBottomLeftValue(TreeNode* root) {
        int maxDepth = 0;
        int leftVal = root->val;
        findValue(root, maxDepth, leftVal, 0);
        return leftVal;
    }
private:
    void findValue(TreeNode* root, int& maxDepth, int& value, int depth) {
        if(!root) return; 
        
        findValue(root->left, maxDepth, value, depth+1);
        findValue(root->right, maxDepth, value, depth+1);
        
        if(depth>maxDepth) {
            maxDepth=depth;
            value=root->val;
        }
    }
};