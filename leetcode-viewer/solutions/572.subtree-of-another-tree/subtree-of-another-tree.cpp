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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        string ss=serialize(s);
        string ts=serialize(t);
        return ss.find(ts)!=std::string::npos;
    }
private:
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }
    
    void serialize(TreeNode* root, ostringstream& out) {
        if(root==NULL) {
            out << " " << "#";
        }
        else {
            out << " " << to_string(root->val);
            serialize(root->left, out);
            serialize(root->right, out);
        }
    }
};