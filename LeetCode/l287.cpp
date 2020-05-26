class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast=0,slow=0;
        fast=nums[nums[fast]];
        slow=nums[slow];
        while(fast!=slow){
            fast=nums[nums[fast]];
            slow=nums[slow];
        }
        slow=0;
        while(fast!=slow){
            fast=nums[fast];
            slow=nums[slow];
        }
        return slow;
    }
};
//https://blog.csdn.net/u012534831/article/details/74231581