class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int w,l,r,len=nums.size();
        if(len<3)return len;
        w=0;
        for(int i=0;i<len-2;i++){
            if(nums[i]!=nums[i+2]){
                nums[w++]=nums[i];
            }
        }
        nums[w++]=nums[len-2];
        nums[w++]=nums[len-1];
        return w;
    }
};