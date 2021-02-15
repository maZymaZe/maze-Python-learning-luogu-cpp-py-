class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0,ma=0;
        for(int i:nums)if(i)cnt++,ma=max(ma,cnt);else cnt=0;
        return ma;
    }
};