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
    vector<int> findMode(TreeNode* root) {
        map<int, int> cnt;
        vector<int> res;
        
        int maxcnt=getmap(root, cnt);
        for(auto c:cnt) {
            if(c.second==maxcnt) res.push_back(c.first);
        }
        return res;
    }
private:
    int getmap(TreeNode* root, map<int, int>& cnt) {
        if(root==NULL) return 0;
        
        cnt[root->val]++;
        
        return max(cnt[root->val], max(getmap(root->left, cnt), getmap(root->right, cnt)));
    }
    
};