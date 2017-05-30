class Solution {
public:
    vector<string> generatePalindromes(string s) {
        unordered_map<char, int> cnt;
        vector<string> res;
        
        for(int i=0; i<s.size(); ++i) cnt[s[i]]++;
        
        int odd=0; 
        string half;
        char mid;
        for(auto x: cnt) {
            if(x.second%2==1) {
                odd++;
                mid=x.first;
                if(odd>1) return res;
            }
            half.append(x.second/2, x.first);
        }
        
        cout << half << endl;
        unordered_set<string> perm;
        permutation(half, vector<bool>(half.size(), 0), "", perm);
        
        for(string str: perm) {
            string newstr=str;
            if(odd) newstr+=mid;
            reverse(str.begin(), str.end());
            newstr+=str;
            res.push_back(newstr);
        }
        return res;
    }
private:
    void permutation(string s, vector<bool> used, string cur, unordered_set<string>& res) {
        if(cur.size()==s.size()) {
            res.insert(cur);
        }
        
        for(int i=0; i<s.size(); ++i) {
            if(i>0 && s[i]==s[i-1] && !used[i-1]) continue;
            if(!used[i]) {
                char tmp=s[i];
                used[i]=true;
                permutation(s, used, cur+tmp, res);
                used[i]=false;
            }
        }
    }
};