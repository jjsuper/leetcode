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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if(n<1) return res;
        return generateTrees(1, n);
    }
private:
    vector<TreeNode*> generateTrees(int n, int m) {
        vector<TreeNode*> res;
        
        if(n==m) {
            TreeNode* tmp=new TreeNode(n);
            res.push_back(tmp);
            return res;
        } 
        
        if(n>m)
        {
            res.push_back(NULL);
            return res;
        }
        
        for(int i=n;i<=m;++i)
        {
            vector<TreeNode*> left=generateTrees(n, i-1);
            vector<TreeNode*> right=generateTrees(i+1, m);
            
            for(int j=0; j<left.size(); ++j)
                for(int k=0; k<right.size(); ++k)
                {
                    TreeNode* root=new TreeNode(i);
                    root->left=left[j];
                    root->right=right[k];
                    res.push_back(root);
                }
        }
        
        return res;
    }
};