class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int l=nums.size();
        if(!l) return 0;
        int pre=nums[0],cnt=1,ans=1;
        for(int i=1;i<l;i++){
            if(nums[i]>pre) pre=nums[i],cnt++;
            else cnt=1,pre=nums[i];
            ans=max(ans,cnt);
        }
        return ans;
    }
};