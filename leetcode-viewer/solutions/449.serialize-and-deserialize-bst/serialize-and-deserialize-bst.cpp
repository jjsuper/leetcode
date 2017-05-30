/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        if(root==NULL) return res;
        res=to_string(root->val)+','+serialize(root->left)+serialize(root->right);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> d=getdata(data);
        
        return deserial(d);
    }
private:
    TreeNode* deserial(vector<int> d) {
        TreeNode* root;
        if(d.empty()) return NULL;
        root=new TreeNode(d[0]);
        
        int i=0;
        while(i<d.size()&&d[i]<=d[0]) i++; 
        
        root->left=deserial(vector<int>(d.begin()+1, d.begin()+i));
        root->right=deserial(vector<int>(d.begin()+i, d.end()));
        
        return root;
    }
    vector<int> getdata(string data) {
        vector<int> res;
        int i=0;

        while(i<data.size()) {
            int j=i;
            while(i<data.size() && data[i]!=',') i++;
            res.push_back(stoi(data.substr(j,i-j)));
            i++;
        }
        
        return res;        
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));