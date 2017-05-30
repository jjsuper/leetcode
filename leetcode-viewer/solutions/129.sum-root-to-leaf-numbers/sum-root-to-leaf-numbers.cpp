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
    int sumNumbers(TreeNode* root) {
        if(root==NULL) return 0;
        return sumRer(root, 0);
    }
    
    int sumRer(TreeNode* root, int num)
    {
        int sum=num*10+root->val;
        if(root->left==NULL && root->right==NULL) return sum;
        if(root->left==NULL) return sumRer(root->right, sum);
        if(root->right==NULL) return sumRer(root->left, sum);
        return sumRer(root->right, sum)+sumRer(root->left, sum);
    }
};