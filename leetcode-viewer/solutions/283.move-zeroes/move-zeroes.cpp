class Solution {
public:
    void moveZeroes(vector<int>& nums) {
 
        int p=0;
       bool flag=1;
       for(int i=0;i<nums.size();++i)
       {
           if(flag)
           {
               if(nums[i]==0)
               {
                   flag=0;
                   p=i;
               }
           }
           else
           {
               if(nums[i]!=0)
               {
                    nums[p]=nums[i];
                    nums[i]=0;
                    p++;
               }
           }
           
       }
 /*
    int p=0;
    for(int i=0;i<nums.size();++i)
       {
            if(nums[i]!=0)
               {
                    nums[p]=nums[i];
                    nums[i]=0;
                    p++;
               }
       }
 */
        
        
    }
};