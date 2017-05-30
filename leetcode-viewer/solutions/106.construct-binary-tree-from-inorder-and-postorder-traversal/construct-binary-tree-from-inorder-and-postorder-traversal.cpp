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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
private:
    TreeNode* buildTree(vector<int>& inorder, int ibegin, int iend, vector<int>& postorder, int pbegin, int pend) {
        if(ibegin>=iend || pbegin>=pend) return NULL;
        
        int mid=postorder[pend-1];
        
        TreeNode *root=new TreeNode(mid);
        
        auto f = find(inorder.begin(), inorder.end(), mid);
        int diff=f-inorder.begin()-ibegin;
        
        root->left=buildTree(inorder, ibegin, ibegin+diff , postorder, pbegin, pbegin+diff);
        root->right=buildTree(inorder, ibegin+diff+1, iend, postorder, pbegin+diff, pend-1);
        
        return root;
    }
};