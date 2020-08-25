class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size(),t=0;
        for(int i=0;i<n;i++)t^=i^nums[i];
        return t^n;
    }
};