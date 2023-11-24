class Solution {
   public:
    int countPairs(vector<int>& nums, int target) {
        int l=nums.size(),ans=0;
        for(int i=0;i<l;i++){
            for(int j=i+1;j<l;j++){
                ans+=(nums[i]+nums[j]<target);
            }
        }
        return ans;
    }
};