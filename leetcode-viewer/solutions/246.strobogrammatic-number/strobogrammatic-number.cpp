class Solution {
public:
    bool isStrobogrammatic(string num) {
        map<char, char> t{{'1','1'},{'6','9'},{'8','8'},{'9','6'},{'0','0'}};
        
        for(int i=0; i<(num.size()+1)/2; ++i) {
            if(t.find(num[i])==t.end() || t[num[i]]!=num[num.size()-1-i])
                return false;
        }
        return true;
    }
};