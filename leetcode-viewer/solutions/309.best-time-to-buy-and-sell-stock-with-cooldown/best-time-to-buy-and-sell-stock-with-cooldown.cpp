class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy0=INT_MIN, buy1=INT_MIN, sell0=0, sell1=0;
        
        for(auto it: prices)
        {
            buy0=buy1;
            buy1=max(sell0-it,buy1);
            sell0=sell1;
            sell1=max(buy0+it,sell1);
        }
        return sell1;
    }
};