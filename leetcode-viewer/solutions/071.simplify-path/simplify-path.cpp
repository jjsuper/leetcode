class Solution {
public:
    string simplifyPath(string path) {/*
        stack<string> s;
        int i=0;
        
        while(i<path.size()) {
            int len=1;
            if(path[i]=='/') {
                while(path[i+len]!='/'&&i+len<path.size()) len++;
                cout << len;
                if(len>1) {
                    string cur=path.substr(i+1, len-1);
                    cout<< cur;
                    if(cur=="..") {
                        if(!s.empty()) s.pop();
                    }
                    else if(cur!=".") {
                        s.push(cur);
                    }
                }
            }
            i=i+len;
        }
        
        string res="";
        while(!s.empty()) {
            res='/'+s.top()+res;
            s.pop();
        }
        
        return res.empty() ? "/" : res;*/
        stringstream is(path);
        stack<string> s;
        string cur;
        while(getline(is, cur, '/')) {
            if(cur=="" || cur==".") continue;
            else if(cur=="..") { 
                if(!s.empty()) s.pop();
            }
            else s.push(cur);
        }
        
        
        string res="";
        while(!s.empty()) {
            res='/'+s.top()+res;
            s.pop();
        }
        
        return res.empty() ? "/" : res;
        
    }
};