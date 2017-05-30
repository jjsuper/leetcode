class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if(m.count(key)) {
            auto curBucket=m[key], nextBucket=++m[key];
            if(nextBucket==buckets.end()) {
                Bucket newBucket(curBucket->val+1, key);
                buckets.push_back(newBucket);
                m[key] = --buckets.end();
            }
            else if (nextBucket->val != curBucket->val+1) {
                Bucket newBucket(curBucket->val+1, key);
                m[key] = buckets.insert(nextBucket, newBucket);
            }
            else {
                nextBucket->keys.insert(key);
                m[key] = nextBucket;
            }
            curBucket->keys.erase(key);
            if(curBucket->keys.empty()) buckets.erase(curBucket);
        }
        else {
            if(buckets.empty() || buckets.front().val != 1) {
                Bucket newBucket(1, key);
                buckets.push_front(newBucket);
            }
            else 
                buckets.front().keys.insert(key);

            m[key] = buckets.begin();
        }
        //dumpList();
       //dump();
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(!m.count(key)) return;
        auto curBucket=m[key];
        if(curBucket->val == 1) {
            curBucket->keys.erase(key);
            if(curBucket->keys.empty()) buckets.erase(curBucket);
            m.erase(key);
            return;
        }
        auto preBucket = --m[key];
        if(curBucket == buckets.begin()) {
            Bucket newBucket(curBucket->val-1, key);
            buckets.push_front(newBucket);
            m[key]=buckets.begin();
        }
        else if (curBucket->val != preBucket->val+1) {
            cout << "in" << endl;
            Bucket newBucket(curBucket->val-1, key);
            m[key] = buckets.insert(curBucket, newBucket);
        }
        else {
            preBucket->keys.insert(key);
            m[key]=preBucket;
        }
        
        
        curBucket->keys.erase(key);
        if(curBucket->keys.empty()) buckets.erase(curBucket);
        dumpList();
        //cout << "dec";
        //dump();
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return buckets.empty()? "": *(buckets.back().keys.begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return buckets.empty()? "": *(buckets.front().keys.begin());
    }
private:
    struct Bucket {
        int val; unordered_set<string> keys;
        Bucket(int v, string s) {
            val=v;
            keys.insert(s);
        }
    };
    list<Bucket> buckets;
    unordered_map<string, list<Bucket>::iterator> m;
    
    void dump() {
        for(auto it : m) {
            cout << it.first << " " << it.second->val << endl; 
        }
        
        cout << endl << endl;
    }
    
    void dumpList() {
        for(auto b : buckets) {
            cout << b.val << " ";
            for(auto key: b.keys) {
                cout << key << " ";
            }
        }
        cout << endl << endl;
    }
    
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */