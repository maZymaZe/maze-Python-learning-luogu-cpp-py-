class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int l=nums.size(),pre=nums[0],ans=nums[0];
        for (int i=1;i<l;i++) {
            pre=max(pre+nums[i],nums[i]);
            ans=max(ans,pre);
        }
        return ans;
    }
};