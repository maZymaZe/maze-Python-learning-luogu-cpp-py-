class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l=nums.size();
        int p=0,q=l-1,t=nums[p]+nums[q];
        while(t!=target){
            if(t>target)q--;
            else p++;
            t=nums[p]+nums[q];
        }
        return {nums[p],nums[q]};
    }
};