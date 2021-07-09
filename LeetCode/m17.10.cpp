class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c=0,n=0,l=nums.size();
        for(int i=0;i<l; i++){
            if(c){
                if(n==nums[i])c++;
                else c--;
            }else{
                n=nums[i];
                c++;
            }
        }
        if(!c)return -1;
        int d=n;c=0;
        for(int i=0;i<l;i++){
            if(d==nums[i])c++;
        }
        if(c>l/2)return d;
        return -1;
        

    }
};