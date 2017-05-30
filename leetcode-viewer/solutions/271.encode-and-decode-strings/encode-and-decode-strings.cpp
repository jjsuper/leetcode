class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encode="";
        for(auto str: strs) {
            encode+=to_string(str.size())+'@'+str;
        }
        return encode;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int head=0;
        while(head<s.size()) {
            int pos=s.find_first_of('@', head);
            int len=stoi(s.substr(head, pos-head));
            head=pos+1;
            res.push_back(s.substr(head, len));
            head+=len;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));