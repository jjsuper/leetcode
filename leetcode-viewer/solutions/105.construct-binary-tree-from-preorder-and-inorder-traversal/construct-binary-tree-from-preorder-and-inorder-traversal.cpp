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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
private:
    TreeNode* buildTree(vector<int>& preorder, int pbegin, int pend, vector<int>& inorder, int ibegin, int iend) {
        if(ibegin>=iend || pbegin>=pend) return NULL;
        
        int mid=preorder[pbegin];
        
        TreeNode *root=new TreeNode(mid);
        
        auto f = find(inorder.begin(), inorder.end(), mid);
        int diff=f-inorder.begin()-ibegin;
        
        root->left=buildTree(preorder, pbegin+1, pbegin+1+diff, inorder, ibegin, ibegin+diff);
        root->right=buildTree(preorder, pbegin+1+diff, pend, inorder, ibegin+diff+1, iend);
        
        return root;
    }        
};