class Solution {
public:
    string getHint(string secret, string guess) {
       int A=0, B=0;
       int count[10]={0};
       int gold[10]={0};
       
       for(int i=0;i<secret.size();++i)
       {
           if(secret[i]==guess[i])
            A++;
            
            gold[secret[i]-'0']++;
            count[guess[i]-'0']++;
        
       }
       
       
       for(int j=0;j<10;++j)
       {
           B=B+min(gold[j],count[j]);
           
       }
       
       B=B-A;
        
        
        
        
        
       ostringstream hint;
       hint << A << "A" << B << "B";
       
       return hint.str();
    }
};