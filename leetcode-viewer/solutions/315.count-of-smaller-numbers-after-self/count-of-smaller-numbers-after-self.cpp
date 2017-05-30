class Solution {
public:/*
    vector<int> countSmaller(vector<int>& nums) {
        
        node* root=NULL;    
        vector<int> res(nums.size(), 0);
        for(int i=nums.size()-1; i>-1; i--) {
            root = insert(root, nums[i], res, i, 0);
        }
        
        return res;
    }
private:
    struct node {
        node* left=NULL;
        node* right=NULL;
        int val;
        int sum;
        int dup=1;
        node(int x, int s) : val(x), sum(s) {}
    };
    
    node* insert(node* root, int num, vector<int>& res, int i, int preSum) {
        if(root == NULL) {
            root = new node(num, 0);
            res[i]=preSum;
        }
        else if(root->val == num) {
            root->dup++;
            res[i]=preSum + root->sum;
        }
        else if(root->val < num) {
            root->right = insert(root->right, num, res, i, preSum+root->sum+root->dup);
        }
        else {
            root->sum++;
            root->left = insert(root->left, num, res, i, preSum);
        }
        return root;
        
    }   
       */ 
    vector<int> countSmaller(vector<int>& nums) {    
        vector<int> indices(nums.size(), 0);
        for(int i=0; i<nums.size(); ++i) {
            indices[i]=i;
        }
        vector<int> res(nums.size(), 0);
        
        mergesort(nums, indices, res, 0, nums.size());
        return res;
    }
private:
    void mergesort(vector<int>& nums, vector<int>& indices, vector<int>& res, int start, int end) {
        if(start+1>=end) return;
        
        int mid=(start+end)/2;
        mergesort(nums, indices, res, start, mid);
        mergesort(nums, indices, res, mid, end);
        
        vector<int> tmp(end-start, 0);
        
        int rightcnt=0;
        int idx1=start;
        int idx2=mid;
        
        while(idx1<mid || idx2<end) {
            if(idx2==end || (idx1<mid && nums[indices[idx1]]<=nums[indices[idx2]])) {
                tmp[idx1-start+idx2-mid]=indices[idx1];
                res[indices[idx1]]+=rightcnt;
                idx1++;
            }
            else {
                tmp[idx1-start+idx2-mid]=indices[idx2];
                rightcnt++;
                idx2++;
            }
        }/*
        while(idx1<mid) {
            tmp[idx1-start+idx2-mid]=indices[idx1];
            res[indices[idx1]]+=rightcnt;
            idx1++;
        }
        while(idx2<end) {
            tmp[idx1-start+idx2-mid]=indices[idx2];
            idx2++;
        }
*/
        
        for(int i=start; i<end; ++i) {
            indices[i]=tmp[i-start];
        }

    }
};