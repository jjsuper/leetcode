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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        recursion(root,1,ret);
        return ret;
    }
    
    void recursion(TreeNode* root, int level, vector<int>& ret)
    {
        if(root==NULL) return;
        if(ret.size()<level) ret.push_back(root->val);
        recursion(root->right, level+1, ret);
        recursion(root->left, level+1, ret);
    }
    
};