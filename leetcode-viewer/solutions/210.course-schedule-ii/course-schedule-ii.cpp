class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> order;
        vector<set<int>> outbound(numCourses);
        vector<int> inbound(numCourses, 0);
        
        for(int i=0; i<prerequisites.size(); ++i) {
            outbound[prerequisites[i].second].insert(prerequisites[i].first);
         //   inbound[prerequisites[i].first]++;
        }
        
        for(int i=0; i<numCourses; ++i) {
            for(auto it=outbound[i].begin(); it!=outbound[i].end(); ++it) {
                inbound[*it]++;
            }
        }
        
        
        queue<int> myque;
        for(int i=0; i<numCourses; ++i) {
            if(!inbound[i]) myque.push(i); 
        }
        
        while(!myque.empty()) {
            int n=myque.front();
            myque.pop();
            order.push_back(n);
            for(auto it=outbound[n].begin(); it!=outbound[n].end(); ++it) {
                int m=*it;
                inbound[m]--;
                if(!inbound[m]) myque.push(m);
            }
            numCourses--;
        }
        
        if(numCourses==0)
            return order;
        else
            return vector<int>();
    }
};