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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root, res);
        return res;
    }
private:
    int dfs(TreeNode* root, vector<vector<int>>& res) {
        if(root==NULL) return 0;
        int level=max(dfs(root->left, res), dfs(root->right, res))+1;
        if(level>res.size()) res.push_back({});
        res[level-1].push_back(root->val);
        return level;
    }
};