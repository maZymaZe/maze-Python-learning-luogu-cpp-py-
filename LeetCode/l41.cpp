class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        nums.push_back(-1);
        nums.push_back(-1);
        int l=nums.size(),sp=200000001;
        for(int i=0;i<l;i++){
            int p=nums[i],r;
            while(p>0&&p<l){
                r=nums[p];
                nums[p]=sp;
                p=r;
            }
        }
        for(int i=1;i<l;i++){
            if(nums[i]!=sp)return i;
        }
        return 0;
    }
};