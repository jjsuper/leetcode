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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> out;
        stack<pair<TreeNode*, string>> path;
        

        if(root==NULL) return out;
        
        string s;
        s=to_string(root->val);
        
        //cout << s;
        
        path.push(pair<TreeNode*, string>(root,s));
        
        while(!path.empty())
        {
            pair<TreeNode*, string> ppair;
            ppair=path.top();
            
            TreeNode* tmpNode;
            string tmpstr;
            tmpNode=get<0>(ppair);
            tmpstr=get<1>(ppair);
            
            path.pop();
            
            
            if(!tmpNode->left&&!tmpNode->right)
            {
                out.push_back(tmpstr);
            }
            
            if(tmpNode->left)
            {
               TreeNode* tmpleft=tmpNode->left;
               string tmpleftstr;
               
               tmpleftstr=tmpstr+"->"+to_string(tmpNode->left->val);
               path.push(pair<TreeNode*, string>(tmpleft,tmpleftstr));
            }
            if(tmpNode->right)
            {
               TreeNode* tmpright=tmpNode->right;
               string tmprightstr;
               
               tmprightstr=tmpstr+"->"+to_string(tmpNode->right->val);
               path.push(pair<TreeNode*, string>(tmpright,tmprightstr));
            }
            
        }
        
        
        return out;
    }
};