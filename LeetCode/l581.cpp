class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> tmp(nums.begin(),nums.end());
        sort(tmp.begin(),tmp.end());
        int i,j,l;
        l=nums.size();
        for(i=0;i<l;i++){
            if(nums[i]!=tmp[i])break;
        }
        for(j=l-1;j>=0;j--){
            if(nums[j]!=tmp[j])break;
        }
        if(i==l)return 0;
        else return j-i+1;
    }
};