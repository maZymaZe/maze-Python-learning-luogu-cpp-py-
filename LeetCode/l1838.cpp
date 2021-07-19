class Solution {
   public:
    int maxFrequency(vector<int>& nums, int k) {
        int l = nums.size();
        sort(nums.begin(), nums.end());
        long long p = 0, q = 0, target = nums[0], tot = 0, ans = 1;
        while(q+1<l&&nums[q]==nums[q+1]){
            q++;            
        }
        ans=q-p+1;
        for(int i=q+1;i<l;i++){
            if(i+1>=l||nums[i]!=nums[i+1]){
                
                tot+=(long long)(q-p+1)*(nums[i]-nums[q]);
                q=i;
                while(tot>k){
                    tot-=nums[i]-nums[p];
                    p++;
                }
                ans=max(ans,q-p+1);
            }
        }
        return ans;
    }
};