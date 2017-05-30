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
    vector<int> largestValues(TreeNode* root) {
        preorder(root, 0);
        return res;
    }
private:
    vector<int> res;
    void preorder(TreeNode* root, int depth) {
        if(!root) return;
        
        if(depth==res.size()) 
            res.push_back(root->val);
        else 
            res[depth]=max(res[depth], root->val);
        
        preorder(root->left, depth+1);
        preorder(root->right, depth+1);
        
    }
};