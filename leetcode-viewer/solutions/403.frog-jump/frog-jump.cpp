class Solution {
public:
   /* bool canCross(vector<int>& stones) {
        
        int k=1;
        for(int i=2; i<stones.size(); ++i) {
            int gap=stones[i]-stones[i-1];
            if(gap<k-1 || gap>k+1) return false;
            k=gap;
        }
        return true;
          //[0,1,3,5,6,8,12,17]
        
        
        return canCross(stones, 0, 0);
        
        
    }*/
/*
unordered_map<int, bool> dp;

bool canCross(vector<int>& stones, int pos = 0, int k = 0) {
    int key = pos | k << 11;

    if (dp.count(key) > 0)
        return dp[key];

    for (int i = pos + 1; i < stones.size(); i++) {
        int gap = stones[i] - stones[pos];
        if (gap < k - 1)
            continue;
        if (gap > k + 1)
            return dp[key] = false;
        if (canCross(stones, i, gap))
            return dp[key] = true;
    }

    return dp[key] = (pos == stones.size() - 1);
    }*/
    
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> hash;
        
        for(int i=0; i<stones.size(); ++i) {
            hash.insert(make_pair(stones[i], unordered_set<int>()));
        }
        hash[stones[0]].insert(0);
        
        for(int i=0; i<stones.size(); ++i) {
            for(auto k: hash[stones[i]]) {
                for(int step=k-1; step<=k+1; ++step) {
                    if(step>0 && hash.count(step+stones[i])>0){
                        hash[step+stones[i]].insert(step);
                    }
                }
            }
        }
        
        return hash[stones[stones.size()-1]].size()>0;
    }
    
};