class Solution {
public:
   unordered_map<int, int> path;
    bool isHappy(int n) {
        //if(n==1) return true;
        //if(path.find(n)!=path.end()) return false;
        
        int r;
        int q=n;
        int sum=0;
        
        
        while(q)
        {
          
          r=q%10;
          
          sum += r*r; 
          q=q/10;  
        }
        
        if(sum==1) return true;
        if(path.find(sum)!=path.end()) return false;
        
        path[n]=sum;
        
        return isHappy(sum);
  /*    
        
        unordered_map<int, int> path;//I use the map to store the result of each calculation. if 19 is the key,the value is 82:1*1+9*9=82
    bool isHappy(int n) {
        int value=0;
        int key=n;
        while (n) {//calculate the value of the key.
            int temp = n%10;
            value+=temp*temp;
            n/=10;
        }
        if (value==1) {//if the value is 1,the key is a happy number.
            return true;
        }
        if (path.find(value)!=path.end()) {//if the value is already in the map,there is a cycle,so the key is not a happy number.
            return false;
        }
        path[key]=value;//put the key/value in the map
        return isHappy(value);//calculate recursively
       /*/ 
    }
};