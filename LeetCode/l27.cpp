class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len= nums.size(),r=0;
        for(int i=0;i<len;i++){
            if(nums[i]!=val)nums[r++]=nums[i];
        }
        return r;
    }
};