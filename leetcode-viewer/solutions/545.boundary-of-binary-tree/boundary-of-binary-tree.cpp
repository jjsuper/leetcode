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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(root==NULL) return boundary;
        boundary.push_back(root->val);
        leftboundary(root->left);
        leaves(root->left);
        leaves(root->right);
        rightboundary(root->right);
        
        return boundary;
    }
private:
    vector<int> boundary;
    
    void leftboundary(TreeNode* root) {
        if(root==NULL || root->left==NULL && root->right==NULL) return;
        boundary.push_back(root->val);
        if(root->left) leftboundary(root->left);
        else leftboundary(root->right);
    }
    
    void rightboundary(TreeNode* root) {
        if(root==NULL || root->left==NULL && root->right==NULL) return;
        if(root->right) rightboundary(root->right);
        else rightboundary(root->left);
        boundary.push_back(root->val);
    }
    
    void leaves(TreeNode* root) {
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL) boundary.push_back(root->val);
        leaves(root->left);
        leaves(root->right);
    }
};