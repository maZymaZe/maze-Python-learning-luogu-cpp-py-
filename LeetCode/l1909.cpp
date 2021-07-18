class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int l=nums.size();
        for (int i=0; i<l-1;i++){
            if(nums[i]>= nums[i + 1]){
                if(i+2>=l||nums[i+2]>nums[i]){
                    for(int j=i+2;j<l-1; j++){
                        if(nums[j]>= nums[j+1])return false;
                    }
                    return true;
                }
                if(i-1<0||nums[i-1]<nums[i+1]){
                    for(int j=i+1;j<l-1; j++){
                        if(nums[j]>= nums[j+1])return false;
                    }
                    return true;
                }
                return false;
            }
        }
        return true;
    }
};