class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int mp[50002]={0},f[50002]={0},l[50002]={0};
        int mx=0,len=nums.size();
        int ans=len;
        for(int i=0;i<len;i++){
            mp[nums[i]]++;
            if(f[nums[i]]==0)f[nums[i]]=i+1;
            l[nums[i]]=i;
        }
        for(int i=0;i<50000;i++)mx=max(mx,mp[i]);
        for(int i=0;i<50000;i++){
            if(mp[i]==mx)ans=min(ans,l[i]-f[i]+2);
        }
        return ans;
    }
};