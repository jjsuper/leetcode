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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        
        vector<TreeNode*> cur;
        cur.push_back(root);
        bool inorder=1;
    
        while(!cur.empty()) {
            vector<TreeNode*> next;
            vector<int> line;
            for(int i=0; i<cur.size(); ++i) {
                TreeNode* tmp = cur[i];
                int num=tmp->val;
                line.push_back(num);
                if(tmp->left) next.push_back(tmp->left);
                if(tmp->right) next.push_back(tmp->right);
            }
            
            if(!inorder) reverse(line.begin(), line.end());
            res.push_back(line);
            
            inorder=!inorder;
            cur.clear();
            cur=next;
        }
        
        return res;
    }
    
    
};