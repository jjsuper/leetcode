class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        m=image.size();
        n=m? image[0].size(): 0;
        
        int left=searchCol(image, 0, y, true);
        cout << "left" << left <<endl;
        int right=searchCol(image, y+1, n, false);
        cout << "right" << right <<endl;
        int top=searchRow(image, 0, x, true);
        cout << "top" << top <<endl;
        int bottom=searchRow(image, x+1, m, false); 
        cout << "bottom" << bottom <<endl;
        
        return (right-left)*(bottom-top);
    }
private:
    int m, n;

    int searchCol(vector<vector<char>>& image, int low, int high, bool opt) {
        while(low<high) {
            int mid=(low+high)/2;
            int i=0;
            while(i<m && image[i][mid]=='0') i++; 
            if(i<m == opt) 
                high=mid;
            else 
                low=mid+1;
        }
        return low;
    }
    
    int searchRow(vector<vector<char>>& image, int low, int high, bool opt) {
        while(low<high) {
            int mid=(low+high)/2;
            int i=0;
            while(i<n && image[mid][i]=='0') i++; 
            if(i<n == opt) 
                high=mid;
            else 
                low=mid+1;
        }
        return low;
    }   
    
    
};