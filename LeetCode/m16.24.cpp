class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int l=nums.size();
        int left=0,right=l-1;
        while (left<right) {
            if(nums[left]+ nums[right]<target)left++;
            else if(nums[left]+ nums[right]>target)right--;
            else ans.push_back({nums[left], nums[right]}),left++,right--;
        }
        return ans;
    }
};