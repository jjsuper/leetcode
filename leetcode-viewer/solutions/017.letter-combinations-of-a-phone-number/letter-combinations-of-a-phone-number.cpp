class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        string temp="";
        if(digits.empty()) return ret;
        recur(digits, ret, temp);
        return ret;
    }
        
        
    void recur(string digits, vector<string>& ret, string temp)
    {
        if(digits.empty()) 
        {
            ret.push_back(temp);
            return;
        }
        
        string s(digits.begin()+1, digits.end());
        
        switch (digits[0])
        {
            case '2':   recur(s, ret, temp+'a');
                        recur(s, ret, temp+'b');
                        recur(s, ret, temp+'c');
                        break;
            case '3':   recur(s, ret, temp+'d');
                        recur(s, ret, temp+'e');
                        recur(s, ret, temp+'f');
                        break;
            case '4':   recur(s, ret, temp+'g');
                        recur(s, ret, temp+'h');
                        recur(s, ret, temp+'i');
                        break;
            case '5':   recur(s, ret, temp+'j');
                        recur(s, ret, temp+'k');
                        recur(s, ret, temp+'l');
                        break;
            case '6':   recur(s, ret, temp+'m');
                        recur(s, ret, temp+'n');
                        recur(s, ret, temp+'o');
                        break;
            case '7':   recur(s, ret, temp+'p');
                        recur(s, ret, temp+'q');
                        recur(s, ret, temp+'r');
                        recur(s, ret, temp+'s');
                        break;
            case '8':   recur(s, ret, temp+'t');
                        recur(s, ret, temp+'u');
                        recur(s, ret, temp+'v');
                        break;
            case '9':   recur(s, ret, temp+'w');
                        recur(s, ret, temp+'x');
                        recur(s, ret, temp+'y');
                        recur(s, ret, temp+'z');
                        break;
        }
        
        
        cout << "end" << endl;
        return;
    }
    
     
        
    
};