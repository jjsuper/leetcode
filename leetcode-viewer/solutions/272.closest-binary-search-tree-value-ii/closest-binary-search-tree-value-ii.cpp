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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        stack<int> pred;
        stack<int> succ;
        inorder(root, target, false, pred);
        inorder(root, target, true,  succ);
        vector<int> res;
        
        while(k>0) {
            if(pred.empty()) {
                res.push_back(succ.top());
                succ.pop();
            }
            else if(succ.empty()) {
                res.push_back(pred.top());
                pred.pop();
            }
            else {
                double pred_diff=target-(double)pred.top();
                double succ_diff=(double)succ.top()-target;
                if(pred_diff<succ_diff) {
                    res.push_back(pred.top());
                    pred.pop();
                }
                else {
                    res.push_back(succ.top());
                    succ.pop();
                }
            }
            k--;
        }
        
        return res;
    }
    
    
private:
    void inorder(TreeNode* root, double target, bool reverse, stack<int>& s) {
        if(root==NULL) return;
        inorder(reverse? root->right: root->left, target, reverse, s);
        if((reverse && root->val<=target) || (!reverse && root->val>target)) return;
        s.push(root->val);
        inorder(reverse? root->left: root->right, target, reverse, s);
    }
};