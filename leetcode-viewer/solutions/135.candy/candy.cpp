class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> num(ratings.size(), 1);
        
        for(int i=1; i<ratings.size(); ++i) {
            if(ratings[i]>ratings[i-1]) num[i]=num[i-1]+1;
        }
        for(int i=ratings.size()-2; i>-1; --i) {
            if(ratings[i]>ratings[i+1]) num[i]=max(num[i], num[i+1]+1);
        }
        
        int sum=0;
        for(int n: num) sum+=n;
        return sum;
    }
};