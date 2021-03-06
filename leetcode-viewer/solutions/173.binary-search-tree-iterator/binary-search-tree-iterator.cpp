/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        pushAll(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !myStack.empty();
    }

    /** @return the next smallest number */
    int next() {
       TreeNode *next=myStack.top();
       myStack.pop();
       pushAll(next->right);
       return next->val;
    }
private:
    stack<TreeNode *> myStack;
    void pushAll(TreeNode *root)
    {
        while(root)
        {
            myStack.push(root);
            root=root->left;
        }
    }
    
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */