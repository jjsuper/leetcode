class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> vec;
        queue<int> que;
        int i;
        
        if(nums.empty()) return vec;
        
        que.push(nums[0]);
        for(i=1;i<nums.size();++i)
        {
            if(nums[i-1]+1!=nums[i])
            {
                string s;
                int head=que.front();
                que.pop();
                if(head==nums[i-1])
                {
                    s=to_string(head);
                    vec.push_back(s);
                }
                else
                {
                    s=to_string(head)+"->"+to_string(nums[i-1]);
                    vec.push_back(s);
                }
                que.push(nums[i]);
            }
        }

        
        while(!que.empty())
        {
            int tmp=que.front();
            que.pop();
            if(tmp==nums.back())
            {
                vec.push_back(to_string(tmp));
            }
            else
            {
                string s;
                s=to_string(tmp)+"->"+to_string(nums.back());
                vec.push_back(s);
            }
        }
        
        return vec;
    }
};