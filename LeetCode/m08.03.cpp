class Solution {
public:
    int findMagicIndex(vector<int>& nums) {
        int l=nums.size(),p=0;
        while(p<l){
            if(p==nums[p])return p;
            else if(p<nums[p])p=nums[p];
            else p++;
        }
        return -1;
    }
};