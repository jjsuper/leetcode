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
    int largestBSTSubtree(TreeNode* root) {
        int res = 0, mn = INT_MIN, mx = INT_MAX;
        isBST(root, mn, mx, res);
        return res;
    }
private:
    bool isBST(TreeNode* root, int& mx, int& mn, int &res) {
        if(!root) return true;
        int l_res=0, r_res=0, l_mx=INT_MAX, l_mn=INT_MIN, r_mx=INT_MAX, r_mn=INT_MIN;
        
        bool left=isBST(root->left, l_mx, l_mn, l_res);
        bool right=isBST(root->right, r_mx, r_mn, r_res);
        
        if(left&&right) {
            if((!root->left || root->val > l_mx) && (!root->right || root->val < r_mn)) {
                res=l_res+r_res+1;
                mx=root->right? r_mx: root->val;
                mn=root->left? l_mn: root->val;
                return true;
            }
        }
        res=max(l_res, r_res);
        return false;
    }
};