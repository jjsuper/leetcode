class FileSystem {
private:
    struct file {
        bool isFile=false;
        unordered_map<string, file*> list;
        string content="";
    };
    
    file* root;
public:
    FileSystem() {
        root=new file();
    }
    
    vector<string> ls(string path) {
        vector<string> res;
        string name;
        int p=0, p1=0;
        file* cur=root;
        while(p<path.size()) {
            for(p1=p+1; p1<path.size() && path[p1]!='/'; ++p1);
            name=path.substr(p+1, p1-p-1);
            if(!name.empty()) {
                if(cur->list.count(name)) {
                    cur=cur->list[name];
                }
                else {
                    return res;
                }
            }
            p=p1;
        }
        if(cur->isFile) 
            res.push_back(name);
        else 
            for(auto it : cur->list) 
                res.push_back(it.first);
        
        sort(res.begin(), res.end());
        return res;
    }
    
    void mkdir(string path) {
        int p=0, p1=0;
        file* cur=root;
        while(p<path.size()) {
            for(p1=p+1; p1<path.size() && path[p1]!='/'; ++p1);
            string name=path.substr(p+1, p1-p-1);
            if(!name.empty()) {
                if(!cur->list.count(name)) {
                    file* newfile = new file();
                    cur->list[name]=newfile;
                }
                cur=cur->list[name];
            }
            p=p1;
        }
    }
    
    void addContentToFile(string filePath, string content) {
        int p=0, p1=0;
        file* cur=root;
        while(p<filePath.size()) {
            for(p1=p+1; p1<filePath.size() && filePath[p1]!='/'; ++p1);
            string name=filePath.substr(p+1, p1-p-1);
            if(!name.empty()) {
                if(!cur->list.count(name)) {
                    file* newfile = new file();
                    cur->list[name]=newfile;
                }
                cur=cur->list[name];
            }
            p=p1;
        }
        cur->isFile=true;
        cur->content+=content;
    }
    
    string readContentFromFile(string filePath) {
        int p=0, p1=0;
        file* cur=root;
        while(p<filePath.size()) {
            for(p1=p+1; p1<filePath.size() && filePath[p1]!='/'; ++p1);
            string name=filePath.substr(p+1, p1-p-1);
            if(!name.empty()) {
                cur=cur->list[name];
            }
            p=p1;
        }
        return cur->content;
    }

};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem obj = new FileSystem();
 * vector<string> param_1 = obj.ls(path);
 * obj.mkdir(path);
 * obj.addContentToFile(filePath,content);
 * string param_4 = obj.readContentFromFile(filePath);
 */