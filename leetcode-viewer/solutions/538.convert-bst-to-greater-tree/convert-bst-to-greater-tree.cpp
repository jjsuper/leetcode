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
    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL) return NULL;
        
        convertBST(root->right);
        int tmp=root->val;
        root->val+=sum;
        sum+=tmp;
        convertBST(root->left);
        
        return root;
    }
private:
    int sum=0;
};