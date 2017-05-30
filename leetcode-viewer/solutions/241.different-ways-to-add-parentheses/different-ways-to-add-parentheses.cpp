class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ret;
        vector<int> left;
        vector<int> right;
        
        for(int i=0; i<input.size(); ++i)
        {
            if(input[i]=='+'||input[i]=='-'||input[i]=='*')
            {
                left=diffWaysToCompute(input.substr(0,i));
                right=diffWaysToCompute(input.substr(i+1));
                
                for(int j=0; j<left.size(); ++j)
                    for(int k=0; k<right.size(); ++k)
                    {
                        switch(input[i])
                        {
                            case '+': ret.push_back(left[j]+right[k]); break;
                            case '-': ret.push_back(left[j]-right[k]); break;
                            case '*': ret.push_back(left[j]*right[k]); break;
                        }
                    }
            }
        }
        
        if(ret.empty())
        {
            int num=0;
            for(int i=0; i<input.size(); ++i)
                num=num*10+input[i]-'0';
            ret.push_back(num);
        }
        
        return ret;
    }
};