class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> pos(amount+1, amount+1);
        pos[0]=0;
        
        for(int i=0; i<pos.size(); ++i) {
            for (auto c: coins) {
                if (c <= i) {
                    pos[i] = min(pos[i], pos[i-c] + 1);
                }
            }
        }
        
        cout << pos[amount] << endl;
        return pos[amount]>amount? -1: pos[amount];
    }
};