class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int> ms;
        vector<vector<int>> ans;
        vector<int> tmp(3);
        for(int i:nums){
            if(ms.count(i))ms[i]=ms[i]+1;
            else ms.insert({i,1});
        }
        int l=nums.size(),pi=9798988,pj=54766768;
        for(int i=0;i<l&&nums[i]<=0;i++){
            if(pi==nums[i])continue;
            else pi=nums[i];
            for(int j=i+1;j<l;j++){
                if(pj==nums[j])continue;
                else pj=nums[j];
                int ned=-nums[i]-nums[j];
                if(ned<0)break;
                if(ned<nums[j])break;
                if(ms.count(ned)&&ms[ned]-(ned==nums[i]?1:0)-(ned==nums[j]?1:0)>0){
                    tmp[0]=nums[i],tmp[1]=nums[j],tmp[2]=ned;
                    ans.push_back(tmp);
                }
            }
        }
        return ans;
    }
};