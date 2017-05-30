class Solution {
public:
    int maxArea(vector<int>& height) {
        int start=0;
        int end=height.size()-1;
        int area=0;
        
        while(start<end)
        {
            int h=min(height[start], height[end]);
            area=max(area, (end-start)*h);
            while(height[start]<=h && start<end) start++;
            while(height[end]<=h && start<end) end--;
        }
        
        return area;
    }
};