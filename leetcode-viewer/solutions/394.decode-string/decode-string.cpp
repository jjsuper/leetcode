class Solution {
public:
    string decodeString(string s) {
        stack<int> numS;
        stack<string> strS;
        int i=0;
        numS.push(1);
        strS.push("");
        
        while(i<s.size()) {
            if(s[i]==']') {
                int num = numS.top();
				string str = strS.top();
				numS.pop();
				strS.pop();
				string tmp;
				for(int i = 0; i < num; ++i){
					tmp += str;
				}
				strS.top() += tmp;
				++i;
            }
            else if(isdigit(s[i])) {
                int pos=s.find_first_of("[", i);
                numS.push(stoi(s.substr(i,pos-i)));
                strS.push("");
                i=pos+1;
            }
            else {
                int pos=s.find_first_of("123456789]", i);
                strS.top() += s.substr(i,pos-i);
                i=pos;
            }
        }
        
        return strS.top();
    }
};