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
    int longestConsecutive(TreeNode* root) {
        int inc=0, dec=0;
        longestPath(root, inc, dec);
        return res;
    }
    
private:
    int res=0;
    void longestPath(TreeNode* root, int& inc, int& dec) {
        if(root==NULL) {
            inc=dec=0;
            return;
        }
        
        inc=dec=1;
        if(root->left) {
            int linc=1, ldec=1;
            longestPath(root->left, linc, ldec);
            if(root->val==root->left->val+1) {
                inc=linc+1;
            }
            else if(root->val==root->left->val-1) {
                dec=ldec+1;
            }
        }
        if(root->right) {
            int rinc=1, rdec=1;
            longestPath(root->right, rinc, rdec);
            if(root->val==root->right->val+1) {
                inc=max(inc, rinc+1);
            }
            else if(root->val==root->right->val-1) {
                dec=max(dec, rdec+1);
            }
        }
        
        res=max(res, inc+dec-1);
        return;
    }
};