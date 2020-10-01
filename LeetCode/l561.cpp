class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int s=nums.size(),ans=0;
        for(int i=0; i<s;i+=2)ans+=nums[i];
        return ans;
    }
};