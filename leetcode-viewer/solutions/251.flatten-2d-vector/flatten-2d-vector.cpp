class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        this->vec2d=vec2d;
        x=0;
        y=0;
    }

    int next() {
        return vec2d[x][y++];
    }

    bool hasNext() {
        while(x < vec2d.size() && vec2d[x].size() == y) {   
            x++; y=0;
        }
        return x<vec2d.size();
    }
private:
    vector<vector<int>> vec2d;
    int x;
    int y;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */