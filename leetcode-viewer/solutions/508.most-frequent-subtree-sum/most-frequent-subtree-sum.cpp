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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> res;
        map<int, int> treesum; 
        int maxsum=0;
        findSum(root, treesum, maxsum);
        
        
        for(auto it=treesum.begin(); it!=treesum.end(); ++it) {
            if(it->second==maxsum) res.push_back(it->first);
        }
        
        return res;
    }
private:
    int findSum(TreeNode*& root, map<int, int>& treesum, int& maxsum) {
        if(root==NULL) return 0;
        
        int sum=root->val;
        
        sum+=findSum(root->left, treesum, maxsum);
        sum+=findSum(root->right, treesum, maxsum);
        
        treesum[sum]++;
        maxsum=max(treesum[sum], maxsum);
        
        return sum;
    }
};