class Solution {
public:
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        hash[url]=longUrl;
        increment(url);
        return url;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        if(hash.find(shortUrl)!=hash.end()) return hash[shortUrl];
        else return "";
    }
    Solution() {
        url="000000";
    }
    
private:
    unordered_map<string, string> hash;
    string url;
    void increment(string url) {
        int carry=1;
        for(int i=5; i>-1; --i) {
            url[i]+=carry;
            carry=0;
            if(url[i]=='z'+1) {
                url[i]='0';
                carry=1;
            }
            else if(url[i]=='Z'+1) {
                url[i]='a';
            }
            else if(url[i]=='9'+1) {
                url[i]='A';
            }
        }
    }
    

};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));