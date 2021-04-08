class Solution {
public:
    int myfindmin(vector<int> &nums, int l,int r){
        if(r==l)return nums[l];
        if(l+1==r)return min(nums[l],nums[r]);
        int mid=(l+r)/2;
        if(nums[mid]> nums[l])return myfindmin(nums,mid,r);
        return myfindmin(nums,l,mid);
    }
    int findMin(vector<int>& nums) {
        if(nums[0]<nums[nums.size()-1])return nums[0];
        return myfindmin(nums,0,nums.size()-1);
    }
};