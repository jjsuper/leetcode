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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        vector<vector<int>> res;
        dfs(root, sum, path, res);
        return res;
    }
private:
    void dfs(TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& res) {
        if(!root) return;
        
        path.push_back(root->val);
        if(!root->left && !root->right && root->val==sum) {
            res.push_back(path);
        } 
        dfs(root->left, sum-root->val, path, res);
        dfs(root->right, sum-root->val, path, res);
        path.pop_back();
    }

};