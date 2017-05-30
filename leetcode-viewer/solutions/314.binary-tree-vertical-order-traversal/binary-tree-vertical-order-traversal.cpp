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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<int>> m;
        queue<pair<TreeNode*, int>> q;
        vector<vector<int>> res;
        
        if(!root) return res;
        q.push(make_pair(root, 0));
        
        while(!q.empty()) {
            TreeNode* p=q.front().first;
            int tmp=q.front().second;
            m[tmp].push_back(p->val);
            q.pop();
            
            if(p->left) q.push(make_pair(p->left, tmp-1));
            if(p->right) q.push(make_pair(p->right, tmp+1));
        }
        
        for(auto it: m) {
            res.push_back(it.second);
        }
        
        return res;
    }
};