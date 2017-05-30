class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res=0;
        
        heights.push_back(0);
        stack<int> index;
        
        for(int i=0; i<heights.size(); ++i) {
            while(index.size()>0 && heights[i]<heights[index.top()]) {
                int h=heights[index.top()];
                index.pop();
                int sidx=index.size()>0? index.top()+1 : 0;
                res=max(res, h*(i-sidx));
            }
            index.push(i);
        }
        
        
        return res;
        
    }
};






