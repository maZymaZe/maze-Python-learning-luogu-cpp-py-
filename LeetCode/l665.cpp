class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int l=nums.size(),f=0;
        for(int i=1;i<l;i++){
            if(nums[i-1]>nums[i]){
                if(f==1)return false;
                f=1;
                if((i-2>=0&&nums[i-2]<=nums[i])||i==1);
                else nums[i]=nums[i-1];
            }
        }
        return true;
    }
};