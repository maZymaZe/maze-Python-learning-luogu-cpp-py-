class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l=nums.size();
        if(l<2)return l;
        int w=l,pre=nums[0],p=1;
        for(int i=1;i<l;i++){
            if(pre==nums[i])w--;
            else pre=nums[i],nums[p++]=nums[i];
        }
        return w;
    }
};