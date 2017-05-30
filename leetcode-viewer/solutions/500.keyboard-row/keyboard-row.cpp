class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        unordered_set<char> row1 {'q', 'w', 'e', 'r', 't', 'y','u', 'i', 'o', 'p'};
        unordered_set<char> row2 {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'}; 
        unordered_set<char> row3 { 'z', 'x', 'c', 'v', 'b' ,'n', 'm'};
        vector<unordered_set<char>> rows {row1, row2, row3};
        
        for(string word: words) {
            int row=0;
            
            for(int k=0; k<3; ++k)
                if(rows[k].find((char)tolower(word[0])) != rows[k].end()) row = k;
            
                
            bool valid=1;
            for(int j=1; j<word.size(); ++j) 
                if(rows[row].find((char)tolower(word[j])) == rows[row].end()) {
                    valid=0;
                    break;
                }
  
            if(valid) res.push_back(word);
        }
        
        return res;
    }
};