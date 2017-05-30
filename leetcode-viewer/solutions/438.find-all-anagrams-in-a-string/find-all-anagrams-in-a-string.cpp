class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map<char, int> m;
        if(s.empty() || p.empty()) return res;
        
        for(int i=0; i<p.size(); ++i) {
            m[p[i]]++;
        }
        
        int left=0, right=0, count=p.size();
        
        while(right < s.size()) {
            if(m[s[right]]>0) count--;
            
            m[s[right]]--;right++;
            
            if(count == 0) res.push_back(left);
            
            if(right - left == p.size() && m[s[left++]]++ >=0) count++;
        }
        
        
        return res;
        
    }
};