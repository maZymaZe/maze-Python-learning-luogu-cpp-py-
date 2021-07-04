class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int l=nums.size();
        vector<int> ans(2),c(l+1);
        for(int i=0;i<l;i++)c[nums[i]]++;
        for (int i =1;i<=l;i++){
            if(c[i]==2)ans[0]=i;
            if(c[i]==0)ans[1]=i;
        }
        return ans;
    }
};