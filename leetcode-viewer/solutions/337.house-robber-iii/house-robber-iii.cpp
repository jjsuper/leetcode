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
    int rob(TreeNode* root) {
        int w,o;
        return node(root, w, o);
    }
    
            
    int node(TreeNode* root, int& w, int& o)
    {
        w=0; 
        o=0;
        if(root==NULL) return 0;
        
        int lw, lo, l, r, rw, ro;
        l=node(root->left, lw, lo);
        r=node(root->right, rw, ro);
        
        w=lo+ro+root->val;
        o=l+r;
        
        cout << root->val << ' ' << max(w,o) << endl;
        return max(w,o);
    }    
        
    
    
    
};