class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> res(findNums.size(), -1);
        
        map<int, int> hashmap;
        stack<int> mystack;
        
        for(auto num: nums) {
            while(!mystack.empty() && num>mystack.top()) {
                int tmp=mystack.top();
                mystack.pop();
                hashmap[tmp]=num;
            }
            mystack.push(num);
        }
        
        for(int i=0; i<findNums.size(); ++i) {
            if(hashmap.find(findNums[i])!=hashmap.end())
                res[i]=hashmap[findNums[i]];
        }
        
        return res;
    }
};