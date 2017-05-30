class Solution {
public:
    int compareVersion(string version1, string version2) {
        int res1=0, res2 = 0;
        int i=0, j=0;
        while (i < version1.size() || j < version2.size()){
            for (; i < version1.size(); i++)
                    if (isdigit(version1[i]))
                        res1 = res1 * 10 + version1[i] - '0';
                    else
                        break;

            for (; j < version2.size(); j++)
                    if (isdigit(version2[j]))
                       res2 = res2 * 10 + version2[j] - '0';
                   else
                       break;

            if (res1 > res2)      return  1;
            else if (res1 < res2) return -1;
            i++;
            j++;
            res1 = 0;
            res2 = 0;
        }
        return 0;
        
        
    }
};