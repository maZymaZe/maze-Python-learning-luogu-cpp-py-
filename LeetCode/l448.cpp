class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int l=nums.size(),p;
        for(int i=0;i<l;i++){
            if(nums[i]>0){
                if(nums[i]==i+1){
                    nums[i]=-nums[i];
                    continue;
                }
                p=i;
                while(nums[nums[p]-1]>0){
                    int t=nums[p];
                    nums[p]=nums[nums[p]-1];
                    nums[t-1]=-t;
                    if(nums[p]==p+1){
                        nums[p]=-nums[p];
                        break;
                    }
                }
            }
        }
        vector<int> ans;
        for(int i=0;i<l;i++)if(nums[i]>0)ans.push_back(i+1);
        return ans;
    }
};