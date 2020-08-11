class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        if(n<5)return 0;
        sort(nums.begin(),nums.end());
        return min(min(nums[n-4]-nums[0],nums[n-1]-nums[3]),min(nums[n-3]-nums[1],nums[n-2]-nums[2]));
    }
};