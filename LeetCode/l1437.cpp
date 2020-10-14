class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        bool flag=true;
        int l=nums.size(),pre;
        for(int i=0; i<nums.size();i++){
            if(nums[i]){
                if(flag){
                    if(i-pre-1<k)return false;
                }else flag=false;
                pre=i;
            }
        }
        return true;
    }
};