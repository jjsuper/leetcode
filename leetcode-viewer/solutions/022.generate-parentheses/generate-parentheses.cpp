class Solution {
public:
    vector<string> generateParenthesis(int n) {
            vector<string> ret;
        string s = "";
        if (n <= 0)
            return ret;

        recurParenthesis(n, n, ret, s);
        
        return ret;
    }

    void recurParenthesis(int leftNum, int rightNum, vector<string> &ret, string temp)
    {
        //leftNum means the number of open parenthesis available,rightNum means the number of close parenthesis available
        if (leftNum == 0 && rightNum == 0)
        {
            ret.push_back(temp);
            return;
        }

        if (leftNum > 0)
            recurParenthesis(leftNum-1, rightNum, ret, temp+'(');

        if (rightNum > 0)
        {
            if (leftNum < rightNum)
                recurParenthesis(leftNum, rightNum-1, ret, temp+')');
        }
    }
        

};