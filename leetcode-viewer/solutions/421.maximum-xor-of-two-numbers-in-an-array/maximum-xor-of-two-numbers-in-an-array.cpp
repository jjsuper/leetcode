class Solution {
private:
    struct TrieNode {
        TrieNode* t[2];
        TrieNode() {t[0]=t[1]=NULL;}
    };
    
    TrieNode* root;
    
    void insert(TrieNode*& root, int num) {
        if(!root) root=new TrieNode();
        TrieNode *p=root;
        for(int i=31; i>=0; i--) {
            int d=((num&(1<<i))>0);
            if(p->t[d]==NULL) 
                p->t[d]=new TrieNode();
            p=p->t[d];
        }
    }
    
public:
    int findMaximumXOR(vector<int>& nums) {
        root=NULL;
        for(auto n:nums)
            insert(root, n);
        
        int maxres=0;
        for(auto n:nums) {
            int value=0;
            TrieNode* p=root;
            for(int i=31; i>=0; i--) {
                int d=((n&(1<<i))>0);
                if(p->t[1-d]) {
                    p=p->t[1-d];
                    value |= (1<<i);
                    //if(value<maxres) break;
                }
                else {
                    p=p->t[d];
                }
            }
            maxres=max(maxres, value);
        }
        
        return maxres;
    }
};