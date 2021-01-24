class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int l=nums.size(),lm;
        if(l==0)return {{}};
        lm=1<<l;
        vector<vector<int>> ans;
        for(int i=0;i<lm;i++){
            vector<int>tmp;
            int t=i,p=0;
            while(t){
                if(t&1)tmp.push_back(nums[p]);
                t>>=1;
                p++;
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};