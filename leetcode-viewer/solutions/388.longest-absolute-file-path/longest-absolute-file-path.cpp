class Solution {
public:
    int lengthLongestPath(string input) {
        vector<int> level(200,0);
        int maxlen=0;
        
        for(int i=0; i<input.size(); ++i) {
            int ln=1;
            int count=0;
            bool isFile=false;
            while(input[i]=='\t') {
                ln++; i++;
            }
            while(input[i]!='\n'&&i<input.size()) {
                count++;
                if(input[i]=='.') isFile=true;
                i++;
            }
            cout << count << endl;
            if(isFile) {
                maxlen=max(maxlen, level[ln-1]+count);
            }
            else {
                level[ln]=level[ln-1]+count+1;
            }
        }
        
        return maxlen;
    }
};