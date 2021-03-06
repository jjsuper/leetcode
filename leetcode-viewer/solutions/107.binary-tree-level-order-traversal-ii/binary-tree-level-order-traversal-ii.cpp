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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        stack<vector<int>> outstack;
        vector<vector<int>> outvector;
        queue<TreeNode*> queue1;
        queue<TreeNode*> queue2;
        
        if (root==NULL) return outvector;
        
        queue1.push(root);
        
        while(!queue1.empty()||!queue2.empty())
        {
            vector<int> vec;
            while(!queue1.empty())
            {
                TreeNode* node;
                node=queue1.front();
                queue1.pop();
                if(node->left!=NULL) queue2.push(node->left);
                if(node->right!=NULL) queue2.push(node->right);
                vec.push_back(node->val);
            }
            
            outstack.push(vec);
            swap(queue1,queue2);
            
        }
        
        
        
        while(!outstack.empty())
        {
            outvector.push_back(outstack.top());
            outstack.pop();
        }
        
        return outvector;
    }
};