class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty())return 0;
        int l=0,r=nums.size()-1;
        if(target>nums[r])return r+1;
        int mid;
        while(l<r){
            if(r==l+1){
                if(nums[l]==target)return l;
                else if(nums[r]==target)return r;
                if(nums[l]>target)return l;
                if(nums[r]<target)return r+1;
                return r;
            }

            mid=(l+r)/2;
            if(nums[mid]==target)return mid;
            else if(nums[mid]>target)r=mid;
            else l=mid;
        }
        return 0;
    }
};