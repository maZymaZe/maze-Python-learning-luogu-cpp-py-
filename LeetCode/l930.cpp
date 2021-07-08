class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> mp;
        mp[0]=1;
        int l=nums.size(),p=0,ans=0;
        for(int i=0; i<l;i++){
            p+=nums[i];
            if(mp.count(p-goal))ans+=mp[p-goal];
            mp[p]++;
        }
        return ans;
    }
};