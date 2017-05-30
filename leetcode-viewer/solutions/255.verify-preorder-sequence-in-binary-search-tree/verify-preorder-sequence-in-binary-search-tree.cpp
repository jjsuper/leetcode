class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> node;
        int root=INT_MIN;
        
        for(int i=0; i<preorder.size(); ++i) {
            if(node.empty() || preorder[i]<node.top()) {
                if(preorder[i]<root) return false;
            }
            else {
                while(!node.empty() && preorder[i]>node.top()) {
                    root=node.top();
                    node.pop();
                }
            }
            node.push(preorder[i]);
        }
        return true;
    }
};