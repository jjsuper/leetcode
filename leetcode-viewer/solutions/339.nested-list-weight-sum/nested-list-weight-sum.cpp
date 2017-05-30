/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        return depthSum(nestedList, 1);
    }
private:
    int depthSum(vector<NestedInteger>& nestedList, int depth) {
        if(nestedList.empty()) return 0;
        int sum=0;
        
        for(int i=0; i<nestedList.size(); ++i) {
            if(nestedList[i].isInteger()) sum+=depth*nestedList[i].getInteger();
            else {
                sum+=depthSum(nestedList[i].getList(), depth+1);
            }
        }
        
        return sum;
    }
};