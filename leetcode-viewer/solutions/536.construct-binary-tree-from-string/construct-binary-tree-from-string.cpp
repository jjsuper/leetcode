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
    TreeNode* str2tree(string s) {
        if(s.empty()) return NULL;
        
        string left="";
        string right="";
        int n=s.size(), i=0, cnt=0;
        
        for(i=0; i<s.size(); ++i) {
            if(s[i]=='(') {
                if(cnt==0) n=i;
                cnt++;
            }
            else if(s[i]==')') {
                cnt--;
                if(cnt==0) break;
            }
        }
        
        cout << s.substr(0,n) << endl;
        
        TreeNode* root=new TreeNode(stoi(s.substr(0,n)));
        if(s.size()>n) {
            left=s.substr(n+1, i-n-1);
            if(i<s.size()-1) {
                right=s.substr(i+2, s.size()-i-3);
            }
        }
        
        root->left=str2tree(left);
        root->right=str2tree(right);
        
        return root;
    }
};