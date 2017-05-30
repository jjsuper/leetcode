class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int ar, ai, br, bi;
        complex(a, ar, ai);
        complex(b, br, bi);
        int rr=ar*br-ai*bi;
        int ri=ai*br+ar*bi;
        return to_string(rr)+"+"+to_string(ri)+"i";
    }
private:
    void complex(string a, int& real, int& image) {
        int index=0, start=0, end=0;
        while(a[index]!='+') index++;
        end=index;
        index++;
        real=stoi(a.substr(start, end-start));
        start=index;
        image=stoi(a.substr(start, a.size()-1-start));
    }
};