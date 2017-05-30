class Solution {
public:
    string originalDigits(string s) {
        vector<int> hash(26,0);
        vector<int> num(10,0);
        
        for(auto c:s) hash[c-'a']++;
        
        if(hash['u'-'a']!=0) {  //4
            int cnt = hash['u'-'a'];
            hash['f'-'a']-=cnt;
            hash['o'-'a']-=cnt;
            hash['u'-'a']=0;
            hash['r'-'a']-=cnt;
            num[4]=cnt;
        }
        if(hash['f'-'a']!=0) {  //5
            int cnt = hash['f'-'a'];
            hash['f'-'a']=0;
            hash['i'-'a']-=cnt;
            hash['v'-'a']-=cnt;
            hash['e'-'a']-=cnt;
            num[5]=cnt;
        }
        if(hash['x'-'a']!=0) {  //6
            int cnt = hash['x'-'a'];
            hash['s'-'a']-=cnt;
            hash['i'-'a']-=cnt;
            hash['x'-'a']=0;
            num[6]=cnt;
        }
        if(hash['s'-'a']!=0) {  //7
            int cnt = hash['s'-'a'];
            hash['s'-'a']=0;
            hash['e'-'a']-=cnt;
            hash['v'-'a']-=cnt;
            hash['e'-'a']-=cnt;
            hash['n'-'a']-=cnt;
            num[7]=cnt;
        }
        if(hash['w'-'a']!=0) {  //2
            int cnt = hash['w'-'a'];
            hash['t'-'a']-=cnt;
            hash['w'-'a']=0;
            hash['o'-'a']-=cnt;
            num[2]=cnt;
        }
        if(hash['z'-'a']!=0) {  //0
            int cnt = hash['z'-'a'];
            hash['z'-'a']=0;
            hash['e'-'a']-=cnt;
            hash['r'-'a']-=cnt;
            hash['o'-'a']-=cnt;
            num[0]=cnt;
        }
        if(hash['o'-'a']!=0) {  //1
            int cnt = hash['o'-'a'];
            hash['o'-'a']=0;
            hash['n'-'a']-=cnt;
            hash['e'-'a']-=cnt;
            num[1]=cnt;
        }
        if(hash['g'-'a']!=0) {  //8
            int cnt = hash['g'-'a'];
            hash['e'-'a']-=cnt;
            hash['i'-'a']-=cnt;
            hash['g'-'a']=0;
            hash['h'-'a']-=cnt;
            hash['t'-'a']-=cnt;
            num[8]=cnt;
        }
        if(hash['i'-'a']!=0) {  //9
            int cnt = hash['i'-'a'];
            hash['n'-'a']-=cnt;
            hash['i'-'a']=0;
            hash['n'-'a']-=cnt;
            hash['e'-'a']-=cnt;
            num[9]=cnt;
        }
        if(hash['h'-'a']!=0) {  //3
            int cnt = hash['h'-'a'];
            hash['t'-'a']-=cnt;
            hash['h'-'a']=0;
            hash['r'-'a']-=cnt;
            hash['e'-'a']-=cnt;
            hash['e'-'a']-=cnt;
            num[3]=cnt;
        }
        
        string res="";
        for(int i=0; i<10; ++i)
            for(int j=0; j<num[i]; ++j)
                res += i+'0';
        
        
        return res;
    }
};