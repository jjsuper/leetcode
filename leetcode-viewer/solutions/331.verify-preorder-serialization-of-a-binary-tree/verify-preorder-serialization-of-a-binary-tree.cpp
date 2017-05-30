class Solution {
public:
    bool isValidSerialization(string preorder) {
        int nullCnt=0, nodeCnt=0;
        int comma=1;
        
        
        for(int i=0; i<preorder.size(); ++i)
        {
            if(preorder[i]==',') 
            {   comma=1;
                continue;
            }
            
            if(preorder[i]=='#' && comma) { nullCnt++; comma=0;}
            else if (comma) { nodeCnt++; comma=0;}
            
            //if(nullCnt>nodeCnt+1) return false;
            if(nullCnt>=nodeCnt+1 && i!=preorder.size()-1) return false;
        }
        
        return nullCnt==nodeCnt+1;
        
        
    }
};